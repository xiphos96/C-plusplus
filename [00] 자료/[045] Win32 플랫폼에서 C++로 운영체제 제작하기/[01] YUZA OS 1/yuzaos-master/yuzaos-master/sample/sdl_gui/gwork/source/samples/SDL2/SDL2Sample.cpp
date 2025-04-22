/*
 *  Gwork
 *  Copyright (c) 2012 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#include <Gwork/Gwork.h>
#include <Gwork/Skins/Simple.h>
#include <Gwork/Skins/TexturedBase.h>
#include <Gwork/Test/TestAPI.h>
#include <Gwork/Input/SDL2.h>
#include <Gwork/Renderers/SDL2.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include<functional.h>
int main(int argc, char** argv)
{
    const Gwk::Point screenSize(640, 480);

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
        return EXIT_FAILURE;

    if (TTF_Init() != 0)
        return EXIT_FAILURE;
    unique_ptr<int> ptr(new int(3));
    ptr.reset(new int(4));  // deletes int(3)
    ptr.reset(NULL);        // deletes int(4)

    //Setup our window and renderer
    SDL_Window *window = SDL_CreateWindow("Gwork SDL2 Sample", 100, 100,
                                          screenSize.x, screenSize.y, SDL_WINDOW_SHOWN);
    if (!window)
        return EXIT_FAILURE;


    // Create a Gwork Allegro Renderer
    //SDL_Renderer *sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//Gwk::Platform::RelativeToExecutablePaths paths(GWORK_RESOURCE_DIR);
	SDL_Renderer* sdlRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
	Gwk::Platform::RelativeToExecutablePaths paths("/");
    

    Gwk::Renderer::SDL2 *renderer = new Gwk::Renderer::SDL2(paths, window);

    // Create a Gwork skin
    auto skin = new Gwk::Skin::TexturedBase(renderer);
    skin->SetRender(renderer);
    skin->Init("DefaultSkin.png");

    // Note, you can get fonts that cover many languages/locales to do Chinese,
    //       Arabic, Korean, etc. e.g. "Arial Unicode" (but it's 23MB!).
    skin->SetDefaultFont("OpenSans.ttf", 11);

    // Create a Canvas (it's root, on which all other Gwork panels are created)
    Gwk::Controls::Canvas* canvas = new Gwk::Controls::Canvas(skin);
    canvas->SetSize(screenSize.x, screenSize.y);
    canvas->SetDrawBackground(true);
    canvas->SetBackgroundColor(Gwk::Color(150, 170, 170, 255));

    // Create our unittest control (which is a Window with controls in it)
    TestAPI* unit = new TestAPI(canvas);
    unit->SetPos(10, 10);

    Gwk::Input::SDL2 input;
    input.Initialize(canvas);
    bool haveQuit = false;

    while (!haveQuit)
    {
        SDL_Event evt;
        while (SDL_PollEvent(&evt))
        {
            if (evt.type == SDL_QUIT)
                haveQuit = true;

            input.ProcessEvent(&evt);
        }

        renderer->BeginContext(nullptr);
        canvas->RenderCanvas();
        renderer->PresentContext(nullptr);
        renderer->EndContext(nullptr);
    }

   // delete unit;
    delete skin;
    delete renderer;

    TTF_Quit();
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}
