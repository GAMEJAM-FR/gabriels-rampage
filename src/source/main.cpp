#include "Constants.hpp"
#include "GameWindow.hpp"

void init_test(GameWindow &win)
{
  win.add_sprite(tTest);
  win.add_text(TITLE, fTest, 50);
  win.add_music(mTest);
}

int main()
{
  GameWindow win;
  init_test(win);
  win.loop(FPS);
  return (0);
}
