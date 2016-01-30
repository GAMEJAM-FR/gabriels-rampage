#ifndef GAMEWINDOW_HPP_
# define GAMEWINDOW_HPP_

# include <vector>

# include "Asset.hpp"
# include "Projectile.hpp"

class Character;
class Player;

class GameWindow
{
private:
  sf::RenderWindow *_window;
  unsigned int _width;
  unsigned int _height;
  std::vector<wrap::Sprite *> _sprites;
  std::vector<wrap::Text *> _texts;
  std::vector<wrap::Music *> _musics;
  std::vector<Character *> _entities;
  sf::View *_view;
  sf::Image *_collision;
  sf::Event _event;
public:
  GameWindow();
  ~GameWindow();
private:
  void input();
  void update(float);
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
  bool checkProjectile(const Projectile &);
public:
  void setView(int, int);
  Character &getPlayer() const;
  sf::Image getCollision() const;
};

#endif /* GAMEWINDOW_HPP_ */
