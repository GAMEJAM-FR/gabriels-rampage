#ifndef GAMEWINDOW_HPP_
# define GAMEWINDOW_HPP_

# include <vector>

# include "Asset.hpp"

class GameWindow
{
private:
  sf::RenderWindow *_window;
  std::vector<wrap::Sprite *> _sprites;
  std::vector<wrap::Text *> _texts;
  std::vector<wrap::Music *> _musics;
  std::vector<int> _event_tab;
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
  void add_sprite(const std::string &);
  void add_text(const std::string &,
		const std::string &,
		unsigned int);
  void add_music(const std::string &);
};

#endif /* GAMEWINDOW_HPP_ */
