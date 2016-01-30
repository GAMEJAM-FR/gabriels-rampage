#ifndef GAMEWINDOW_HPP_
# define GAMEWINDOW_HPP_

# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>
# include <vector>

class GameWindow
{
private:
  sf::RenderWindow *_window;
  std::vector<sf::Sprite *> _sprites;
  std::vector<sf::Music *> _musics;
  std::vector<sf::Text *> _texts;
  sf::Event _event;
  std::vector<int> _event_tab;
public:
  GameWindow();
  ~GameWindow();
private:
  void input();
  void update();
  void draw();
public:
  void init(std::vector<sf::Sprite *> &,
	    std::vector<sf::Text *> &,
	    std::vector<sf::Music *> &);
  void loop(unsigned int);
};

bool operator<<(std::vector<int>, int);

#endif /* GAMEWINDOW_HPP_ */
