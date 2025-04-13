#include "to_utf16.hpp"
#include "paint_event.hpp"
#include "resize_event.hpp"
#include "key_event.hpp"
#include "text_input_event.hpp"
#include "application.hpp"
#include "widget.hpp"
#include <SDL_ttf.h>
#include <SDL.h>
//#include <stdexcept>

#include <algorithm.h>
#include <iostream>
#include <assert.h>

Application *Application::instance_ = nullptr;

Application::Application(int&, char**) :
	focusWidget_(nullptr),
	needUpdateWithoutRedraw_(nullptr),
	lastUpdate_(0)
{
	if (instance_ != nullptr)
	{
        assert("The program can have only one instance of Application\n");
        //throw eastl::runtime_error("The program can have only one instance of Application");
	}
	
	instance_ = this;
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
        assert("SDL_Init Error\n");
        //throw std::runtime_error("SDL_Init Error: " + std::string(SDL_GetError()));
	}
	
	if (TTF_Init() != 0)
	{
		assert("TTF_Init error\n");
        //throw std::runtime_error("TTF_Init error: " + std::string(SDL_GetError()));
	}
}

Application::~Application()
{
  SDL_Quit();
  instance_ = nullptr;
}

int Application::exec()
{
  bool done = false;
  while (!done)
  {
    SDL_Event e;
    if (SDL_WaitEvent(&e))
    {
      switch (e.type)
      {
      case SDL_WINDOWEVENT:
        {
          Widget *w = widgetByWindowId(e.window.windowID);
          switch (e.window.event)
          {
          case SDL_WINDOWEVENT_SHOWN:
            eastl::cout << "Window " << e.window.windowID << " shown" << endl;
            break;
          case SDL_WINDOWEVENT_HIDDEN:
              eastl::cout << "Window " << e.window.windowID << " hidden" << endl;
            break;
          case SDL_WINDOWEVENT_EXPOSED:
            {
              needUpdateWithoutRedraw_ = w;
              break;
            }
          case SDL_WINDOWEVENT_MOVED:
            break;
          case SDL_WINDOWEVENT_RESIZED:
            {
              w->resize(e.window.data1, e.window.data2);
#if __APPLE__==1
              SDL_RenderPresent(w->renderer_); // hack for MacOS X
#endif
              break;
            }
          case SDL_WINDOWEVENT_MINIMIZED:
              eastl::cout << "Window " << e.window.windowID << " minimized" << endl;
            break;
          case SDL_WINDOWEVENT_MAXIMIZED:
              eastl::cout << "Window " << e.window.windowID << " maximized" << endl;
            break;
          case SDL_WINDOWEVENT_RESTORED:
              eastl::cout << "Window " << e.window.windowID << " restored" << endl;
            break;
          case SDL_WINDOWEVENT_ENTER:
              eastl::cout << "Mouse entered window " << e.window.windowID << endl;
            break;
          case SDL_WINDOWEVENT_LEAVE:
              eastl::cout << "Mouse left window " << e.window.windowID << endl;
            break;
          case SDL_WINDOWEVENT_FOCUS_GAINED:
              eastl::cout << "Window " << e.window.windowID << " gained keyboard focus" << endl;
            break;
          case SDL_WINDOWEVENT_FOCUS_LOST:
              eastl::cout << "Window " << e.window.windowID << " lost keyboard focus" << endl;
            break;
          case SDL_WINDOWEVENT_CLOSE:
              eastl::cout << "Window " << e.window.windowID << " closed" << endl;
            break;
          default:
              eastl::cout << "Window " << e.window.windowID << " got unknown event " << static_cast<int>(e.window.event) << endl;
            break;
          }
          break;
        }
      case SDL_KEYDOWN:
        {
          KeyEvent ke { static_cast<KeyEvent::Key>(e.key.keysym.sym), (unsigned int)SDL_GetModState(), static_cast<bool>(e.key.repeat) };
          auto w = focusWidget();
          if (!w)
            w = widgetByWindowId(e.key.windowID);
          else if (w->ancestor() != widgetByWindowId(e.key.windowID))
          {
              eastl::cout << "Unknown windowID " << e.key.windowID << endl;
            break;
          }
          while (w)
          {
            if (w->keyPressEvent(ke))
              break;
            w = w->parent();
          }
          break;
        }
      case SDL_KEYUP:
        {
          KeyEvent ke { static_cast<KeyEvent::Key>(e.key.keysym.sym), (unsigned int)SDL_GetModState(), static_cast<bool>(e.key.repeat) };
          auto w = focusWidget();
          if (!w)
            w = widgetByWindowId(e.key.windowID);
          else if (w->ancestor() != widgetByWindowId(e.key.windowID))
          {
              eastl::cout << "Unknown windowID " << e.key.windowID << endl;
            break;
          }

          while (w)
          {
            if (w->keyReleaseEvent(ke))
              break;
            w = w->parent();
          }
          break;
        }
      case SDL_TEXTINPUT:
        {
          TextInputEvent tie { toUtf16(e.text.text) };
          auto w = focusWidget();
          if (!w)
            w = widgetByWindowId(e.key.windowID);
          else if (w->ancestor() != widgetByWindowId(e.key.windowID))
          {
            eastl::cout << "Unknown windowID " << e.key.windowID << endl;
            break;
          }

          while (w)
          {
            if (w->textInputEvent(tie))
              break;
            w = w->parent();
          }
          break;
        }
      case SDL_QUIT:
        done = true;
        break;
      }
    }
    const auto isEmpty = (SDL_PeepEvents(&e, 1, SDL_PEEKEVENT, SDL_FIRSTEVENT, SDL_LASTEVENT) == 0);
    if (isEmpty || SDL_GetTicks() > lastUpdate_ + 1000 / 60)
    {
      auto x = SDL_GetTicks();
      for (auto w: widgetList_)
        if (w->needRepaint())
        {
          PaintEvent e;
          w->internalPaint(e);
        }
      if (needUpdateWithoutRedraw_)
      {
        needUpdateWithoutRedraw_->updateWithoutRedraw();
        needUpdateWithoutRedraw_ = nullptr;
      }
      lastUpdate_ = SDL_GetTicks();
      eastl::cout << "Update time: " << lastUpdate_ - x << " " <<
        (lastUpdate_ - x > 0 ? 1000 / (lastUpdate_ - x) : 999)<< "fps" << endl;
    }
    for (auto obj: deletingObjects_)
      delete obj;
    deletingObjects_.clear();
  }
  return 0;
}

Application *Application::instance()
{
  return instance_;
}

void Application::addWidget(Widget *w)
{
  widgetList_.push_back(w);
}

void Application::removeWidget(Widget *w)
{
  widgetList_.erase(eastl::remove(begin(widgetList_), end(widgetList_), w), end(widgetList_));
}

Widget *Application::widgetByWindowId(Uint32 id)
{
  for (const auto w: widgetList_)
    if (id == w->windowId())
      return w;
  return nullptr;
}

void Application::setFocusWidget(Widget *value)
{
  focusWidget_ = value;
}

Widget *Application::focusWidget() const
{
  return focusWidget_;
}

void Application::clearFocus()
{
  focusWidget_ = nullptr;
}
