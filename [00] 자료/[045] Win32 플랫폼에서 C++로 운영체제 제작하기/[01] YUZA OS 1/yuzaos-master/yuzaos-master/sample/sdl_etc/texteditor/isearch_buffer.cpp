#include "isearch_buffer.hpp"
#include "screen.hpp"
#include <assert.h>
#include <iostream>
#include <algorithm.h>

using namespace eastl;

IsearchBuffer::IsearchBuffer(Screen *screen):
  screen_(screen),
  initialCursor_(screen_->cursor())
{
  buffer_.push_back(L"I-search:");
}

void IsearchBuffer::postInsert(Coord &, const eastl::wstring &value)
{
  assert(screen_->textBuffer());
  eastl::wstring tmp;
  tmp.resize(value.size());
  eastl::transform(begin(value), end(value), begin(tmp), ::tolower);
  searchString_ += tmp;
  search();
}

int IsearchBuffer::preBackspace(Coord &, int value)
{
  if (searchString_.size() > 0)
    return value;
  else
    return 0;
}

void IsearchBuffer::postBackspace(Coord &, int value)
{
  if (searchString_.size() > 0)
  {
    searchString_.resize(searchString_.size() - value);
    screen_->setCursor(initialCursor_);
    search();
  }
}

void IsearchBuffer::findNext()
{
  if (searchString_.empty())
    return;
  screen_->moveCursorRight();
  if (!search())
  {
    screen_->setCursor(initialCursor_);
    search();
  }
}

bool IsearchBuffer::search()
{
  size_t x = eastl::max(0, static_cast<int>(screen_->cursor().x - searchString_.size()));
  int y = screen_->cursor().y;
  while (y < screen_->textBuffer()->size())
  {
    auto tmpStr = (*screen_->textBuffer())[y];
    eastl::transform(begin(tmpStr), end(tmpStr), begin(tmpStr), ::tolower);
    auto tmp = tmpStr.find(searchString_, x);
    if (tmp != eastl::wstring::npos)
    {
      screen_->setCursor(tmp + searchString_.size(), y);
      screen_->setStartSelection(Coord{ static_cast<int>(tmp), y });
      screen_->setEndSelection(Coord{ static_cast<int>(tmp + searchString_.size()), y });
      return true;
    }
    ++y;
    x = 0;
  }
  return false;
}
