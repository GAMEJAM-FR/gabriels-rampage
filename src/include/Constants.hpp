#ifndef CONSTANTS_HPP_
# define CONSTANTS_HPP_

# include <string>
# include <SFML/Graphics.hpp>

/*
 * game constants
 */
const unsigned int WIDTH = 1024;
const unsigned int HEIGHT = 768;
const std::string RES = "1024x768";
const std::string TITLE = "Monk Genocide";
const unsigned int FPS = 60;
const sf::Keyboard::Key MOVE[4][2] =
  {
    { sf::Keyboard::Left, sf::Keyboard::Q },
    { sf::Keyboard::Up, sf::Keyboard::Z },
    { sf::Keyboard::Right, sf::Keyboard::D },
    { sf::Keyboard::Down, sf::Keyboard::S }
  };
enum Direction
  {
    LEFT,
    UP,
    RIGHT,
    DOWN
  };

/*
 * texture paths
 */
const std::string tTest =
  "asset/map.jpg";

/*
 * font paths
 */
const std::string fTest =
  "asset/LiberationMono-Regular.ttf";

/*
 * music paths
 */
const std::string mTest =
  "asset/nice_music.wav";

#endif /* CONSTANTS_HPP_ */
