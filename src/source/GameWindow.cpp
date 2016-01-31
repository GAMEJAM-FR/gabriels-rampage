#include <iostream>
#include "GameWindow.hpp"
#include "Player.hpp"

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
  _height(HEIGHT)
{
  this->_window->setVerticalSyncEnabled(true);
  this->_view.setCenter(420, 420);
  this->_view.zoom(0.2f);
  this->_entities.push_back(new Player(this, 420, 420));
  this->_ritual.maxTime = 120000;
  this->_ritual.maxEnemy = 30;
  this->_ritual.deadEnemy = 0;
}

GameWindow::~GameWindow()
{
  unsigned int ct = 0;

  while (ct < this->_entities.size())
    {
      delete this->_entities[ct];
      ct++;
    }
  delete this->_window;
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
  std::vector<wrap::Sprite *>::iterator it;

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
  ct = 0;
  while (ct < this->_entities.size())
    {
      if (this->_entities[ct]->getHp() <= 0)
	{
	  it = this->_sprites.begin();
	  while (it != this->_sprites.end())
	    {
	      if (*it == this->_entities[ct]->_sprite)
		{
		  this->_ritual.deadEnemy++;
		  this->_sprites.erase(it);
		  delete this->_entities[ct]->_sprite;
		  break ;
		}
	      it++;
	    }
	  delete this->_entities[ct];
	  this->_entities.erase(this->_entities.begin() + ct);
	}
      else
	{
	  this->_entities[ct]->update(this, time);
	  ct++;
	}
    }
  this->_window->setView(this->_view);
}

void GameWindow::draw()
{
  unsigned int ct = 0;

  this->_window->clear();
  while (ct < this->_sprites.size())
    {
      this->_window->draw(this->_sprites[ct]->_sprite);
      ct++;
    }
  ct = 0;
  while (ct < this->_texts.size())
    {
      this->_window->draw(this->_texts[ct]._text);
      ct++;
    }
  this->_window->display();
}

void GameWindow::loop(unsigned int fps)
{
  sf::Clock clock;
  sf::Clock clock2;
  sf::Time t = sf::milliseconds(1 / (float) fps);
  int ct = 0;

  this->_sprites.insert(this->_sprites.begin(), this->_iSprite);
  this->_texts.push_back(*this->_iText);
  this->_iMusic->_music.play();
  while (this->_window->isOpen())
    {
      t = clock.getElapsedTime();
      if ((float)t.asMilliseconds() / 1000 >= 1 / (float)fps)
	{
	  ct++;
	  if (clock2.getElapsedTime().asSeconds() >= 1)
	    {
	      std::cout << "fps: " << ct << std::endl;
	      ct = 0;
	      clock2.restart();
	    }
	  clock.restart();
	  this->input();
	  this->update((float)t.asMilliseconds() / 1000);
	  this->draw();
	}
      if ((unsigned int)this->_ritual.current.getElapsedTime().asMilliseconds() >= this->_ritual.maxTime)
	break ;
      else if (this->_ritual.deadEnemy >= this->_ritual.maxEnemy)
	break ;
    }
}

void GameWindow::init(wrap::Sprite *s, wrap::Text *t,
		      wrap::Music *m, wrap::Image *i)
{
  this->_iSprite = s;
  this->_iText = t;
  this->_iMusic = m;
  this->_iCollision = i;
}

void GameWindow::setView(int x, int y)
{
  this->_view.setCenter(x, y);
}

Character &GameWindow::getPlayer()
{
  return (*this->_entities[0]);
}

const sf::Image &GameWindow::getCollision()
{
  return (this->_iCollision->_collision);
}

unsigned int GameWindow::getWidth()
{
  return (this->_width);
}

unsigned int GameWindow::getHeight()
{
  return (this->_height);
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
