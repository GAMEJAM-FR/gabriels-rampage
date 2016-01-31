#ifndef GAMEWINDOW_HPP_
# define GAMEWINDOW_HPP_

# include <SFML/Graphics.hpp>
# include "Character.hpp"
# include "Projectile.hpp"
# include "Asset.hpp"

class GameWindow
{
private:
  sf::RenderWindow *_window;
  unsigned int _width;
  unsigned int _height;
  sf::View _view;
  sf::Event _event;
private:
  wrap::Sprite *_iSprite;
  wrap::Text *_iText;
  wrap::Music *_iMusic;
  wrap::Image *_iCollision;
public:
  std::vector<wrap::Sprite*> _sprites;
  std::vector<wrap::Text> _texts;
  std::vector<wrap::Music> _musics;
  std::vector<Character *> _entities;
public:
  GameWindow();
  ~GameWindow();
private:
  void input();
  void update(float);
  void draw();
public:
  void loop(unsigned int);
  void init(wrap::Sprite *, wrap::Text *,
	    wrap::Music *, wrap::Image *);
  bool checkProjectile(const Projectile &);
public:
  void setView(int, int);
  Character &getPlayer();
  const sf::Image &getCollision();
  unsigned int getWidth();
  unsigned int getHeight();
};

#endif /* GAMEWINDOW_HPP_ */
