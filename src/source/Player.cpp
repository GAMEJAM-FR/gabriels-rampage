#include "Player.hpp"
#include "GameWindow.hpp"
#include <iostream>

Player::Player(GameWindow *win, int x, int y) : Character(win, x, y, UP, 15, 8, 0.75, 1, Pl / 2, tMonk, 70, false)
{
  this->_sprite->_sprite.setTextureRect(sf::IntRect(0, 0, Pl, Pl));
}

Player::Player(Player const& copy) : Character(copy)
{
  (void) copy;
}

Player::~Player()
{

}

Player& Player::operator=(Player const& copy)
{
  (void) copy;
  return (*this);
}

void Player::left(GameWindow *win)
{
  collide(win->getCollision(), this->_x - this->_speed, this->_y);
  win->setView(this->_x, this->_y);
  this->_direction = LEFT;
}

void Player::up(GameWindow *win)
{
  collide(win->getCollision(), this->_x, this->_y - this->_speed);
  win->setView(this->_x, this->_y);
  this->_direction = UP;
}

void Player::right(GameWindow *win)
{
  collide(win->getCollision(), this->_x + this->_speed, this->_y);
  win->setView(this->_x, this->_y);
  this->_direction = RIGHT;
}

void Player::down(GameWindow *win)
{
  collide(win->getCollision(), this->_x, this->_y + this->_speed);
  win->setView(this->_x, this->_y);
  this->_direction = DOWN;
}

void Player::update(GameWindow *win, float time)
{
  size_t i;
  std::vector<wrap::Sprite *>::iterator it;

  i = 0;
  if (this->_animation.getElapsedTime().asMilliseconds() > 200)
    {
      this->_animation.restart();
      this->_idx++;
      if (this->_idx > 2)
	this->_idx = 0;
    }
  this->_sprite->_sprite.setTextureRect(sf::IntRect(this->_idx * Pl, (int)this->_direction * Pl, Pl, Pl));
  while (i < this->_projectiles.size())
    {
      if (this->_projectiles[i].update(win, time))
	{
	  it = win->_sprites.begin();
	  while (it != win->_sprites.end())
	    {
	      if (*it == this->_projectiles[i]._sprite)
		{
		  win->_sprites.erase(it);
		  delete this->_projectiles[i]._sprite;
		  break ;
		}
	      it++;
	    }
	  this->_projectiles.erase(this->_projectiles.begin() + i);
	}
      else
	i++;
    }
}

void Player::attack(GameWindow *win)
{
  if ((float)this->_cooldown.getElapsedTime().asMilliseconds() / 1000 > this->_frequency)
    {
      this->_cooldown.restart();
      this->_projectiles.push_back(Projectile(win, this->_x + Pl / 2, this->_y + Pl / 2, this->_attack, this->_direction, this->_range));
      this->_projectiles.push_back(Projectile(win, this->_x + Pl / 2, this->_y + Pl / 2, this->_attack, this->_direction, this->_range));
      this->_projectiles.push_back(Projectile(win, this->_x + Pl / 2, this->_y + Pl / 2, this->_attack, this->_direction, this->_range));
      this->_projectiles.push_back(Projectile(win, this->_x + Pl / 2, this->_y + Pl / 2, this->_attack, this->_direction, this->_range));
      this->_projectiles.push_back(Projectile(win, this->_x + Pl / 2, this->_y + Pl / 2, this->_attack, this->_direction, this->_range));
    }
}

void Player::specialAttack(GameWindow *win)
{
  if ((float)this->_cooldown.getElapsedTime().asMilliseconds() / 1000 > this->_frequency)
    {
      this->_cooldown.restart();
      this->_projectiles.push_back(Projectile(win, this->_x + Pl / 2, this->_y + Pl / 2, this->_attack, this->_direction));
    }
}
