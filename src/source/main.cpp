#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Constants.hpp"
#include "GameWindow.hpp"

bool init_test(GameWindow &win)
{
  std::vector<sf::Sprite *> sNew;
  std::vector<sf::Text *> tNew;
  std::vector<sf::Music *> mNew;

  sf::Texture texture;
  if (!texture.loadFromFile(tTest))
    return (false);
  sNew.push_back(new sf::Sprite(texture));

  sf::Font font;
  if (!font.loadFromFile(fTest))
    return (false);
  tNew.push_back(new sf::Text(TITLE, font, 50));

  sf::Music *music = new sf::Music();
  if (!music->openFromFile(mTest))
    return (false);
  mNew.push_back(music);

  win.init(sNew, tNew, mNew);
  return (true);
}

int main()
{
  GameWindow win;
  if (!init_test(win))
    {
      std::cout << "Failed to instantiate window\n";
      return (1);
    }
  win.loop(FPS);
  return (0);
}
