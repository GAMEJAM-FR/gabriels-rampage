#include "GameWindow.hpp"
#include "Constants.hpp"
#include "Player.hpp"

#include <iostream>

void (Player:: *move[4])(GameWindow *) =
{
  &Player::left,
  &Player::up,
  &Player::right,
  &Player::down
};

GameWindow::GameWindow() :
  _window(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), TITLE)),
  _width(WIDTH),
  _height(HEIGHT),
  _sprites(std::vector<wrap::Sprite *>()),
  _texts(std::vector<wrap::Text *>()),
  _musics(std::vector<wrap::Music *>()),
  _entities(std::vector<Character *>()),
  _view(new sf::View),
  _collision(new sf::Image)
{
  this->_window->setVerticalSyncEnabled(true);
  this->_view->setCenter(420, 420);
  this->_view->zoom(0.2f);
  this->_collision->loadFromFile(iCollision);
  this->_entities.push_back(new Player(420, 420));
}

GameWindow::~GameWindow()
{
  unsigned int ct = 0;

  delete this->_window;
  while (ct < this->_sprites.size())
    {
      delete this->_sprites[ct];
      ct++;
    }
  ct = 0;
  while (ct < this->_texts.size())
    {
      delete this->_texts[ct];
      ct++;
    }
  ct = 0;
  while (ct < this->_musics.size())
    {
      delete this->_musics[ct];
      ct++;
    }
  ct = 0;
  while (ct < this->_entities.size())
    {
      delete this->_entities[ct];
      ct++;
    }
}

void GameWindow::input()
{
  while (this->_window->pollEvent(this->_event))
    {
      if (this->_event.type == sf::Event::Closed)
	{
	  this->_window->close();
	  return ;
	}
      if (this->_event.type == sf::Event::Resized)
	{
	  this->_width = this->_event.size.width;
	  this->_height = this->_event.size.height;
	}
    }
}

void GameWindow::update(float time)
{
  unsigned int ct = 0;

  while (ct < 4)
    {
      if (sf::Keyboard::isKeyPressed(MOVE[ct][0]) || sf::Keyboard::isKeyPressed(MOVE[ct][1]))
	(dynamic_cast<Player *>(this->_entities[0])->*move[ct])(this);
      ct++;
    }
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    dynamic_cast<Player *>(this->_entities[0])->attack(this);
  if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    dynamic_cast<Player *>(this->_entities[0])->specialAttack(this);
  ct = 1;
  while (ct < this->_entities.size())
    {
      this->_entities[0]->update(this, time);
      ct++;
    }
  this->_window->setView(*this->_view);  
}

void GameWindow::draw()
{
  unsigned int ct = 0;

  this->_window->clear();
  while (ct < this->_sprites.size())
    {
      this->_window->draw(**this->_sprites[ct]);
      ct++;
    }
  ct = 0;
  while (ct < this->_texts.size())
    {
      this->_window->draw(**this->_texts[ct]);
      ct++;
    }
  this->_window->display();
}

void GameWindow::loop(unsigned int fps)
{
  sf::Clock clock;
  sf::Time t = sf::milliseconds(1 / (float) fps);
  
  if (this->_musics.size() > 0)
    (**this->_musics[0]).play();
  while (this->_window->isOpen())
    {
      t = clock.getElapsedTime();
      if ((float)t.asMilliseconds() / 1000 >= 1 / (float)fps)
	{
	  clock.restart();
	  this->input();
	  this->update((float)t.asMilliseconds() / 1000);
	  this->draw();
	}
    }
}

void GameWindow::add_sprite(const std::string &path, unsigned int x, unsigned int y, bool bg)
{
  this->_sprites.push_back(new wrap::Sprite(path, x, y, bg));
}

void GameWindow::add_text(const std::string &content, const std::string &path,
			  unsigned int size, unsigned int x, unsigned int y)
{
  this->_texts.push_back(new wrap::Text(content, path, size, x, y));
}

void GameWindow::add_music(const std::string &path, bool loop)
{
  this->_musics.push_back(new wrap::Music(path, loop));
}

void GameWindow::setView(int x, int y)
{
  this->_view->setCenter(x, y);
}

Character &GameWindow::getPlayer() const
{
  return (*this->_entities[0]);
}

sf::Image GameWindow::getCollision() const
{
  return (*this->_collision);
}

bool GameWindow::checkProjectile(const Projectile &ejac)
{
  unsigned int ct = 1;

  while (ct < this->_entities.size())
    {
      if (ejac.getX() >= this->_entities[ct]->getX() - (int)this->_entities[ct]->getHitbox() &&
	  ejac.getX() <= this->_entities[ct]->getX() + (int)this->_entities[ct]->getHitbox() &&
	  ejac.getY() >= this->_entities[ct]->getY() - (int)this->_entities[ct]->getHitbox() &&
	  ejac.getY() <= this->_entities[ct]->getY() + (int)this->_entities[ct]->getHitbox())
	{
	  this->_entities[ct]->takeDamage(ejac.getDamage());
	  return (true);
	}
      ct++;
    }
  return (false);
}
