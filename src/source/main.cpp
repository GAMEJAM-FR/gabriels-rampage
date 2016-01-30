#include "Constants.hpp"
#include "GameWindow.hpp"

void init_test(GameWindow &win)
{
  win.add_sprite(tTest, 0, 0, true);
  win.add_text(TITLE, fTest, 50,
	       WIDTH / 2, HEIGHT / 2);
  win.add_music(mTest, true);
}

int main()
{
  GameWindow win;
  init_test(win);
  win.loop(FPS);
  return (0);
}
