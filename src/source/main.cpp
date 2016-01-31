#include "GameWindow.hpp"
#include <iostream>
int main()
{
  GameWindow win;
  win.init(new wrap::Sprite(tTest, 0, 0, true),
	   new wrap::Text(TITLE, fTest, 50, WIDTH / 2, HEIGHT / 5),
	   new wrap::Music(mTest, true),
	   new wrap::Image(iCollision));
  win.loop(FPS);
  std::cout << "BITE\n";
  return (0);
}
