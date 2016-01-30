#ifndef GAMEWINDOW_HPP_
# define GAMEWINDOW_HPP_

# include <vector>

# include "Asset.hpp"

class GameWindow
{
private:
  sf::RenderWindow *_window;
  unsigned int _width;
  unsigned int _height;
  std::vector<wrap::Sprite *> _sprites;
  std::vector<wrap::Text *> _texts;
  std::vector<wrap::Music *> _musics;
  sf::Event _event;
public:
  GameWindow();
  ~GameWindow();
private:
  void input();
  void update();
  void draw();
public:
  void loop(unsigned int);
  void add_sprite(const std::string &,
		  unsigned int,
		  unsigned int, bool);
  void add_text(const std::string &,
		const std::string &,
		unsigned int,
		unsigned int,
		unsigned int);
  void add_music(const std::string &, bool);
};

#endif /* GAMEWINDOW_HPP_ */
