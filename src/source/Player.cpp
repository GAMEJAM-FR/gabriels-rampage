#include "Player.hpp"
#include "GameWindow.hpp"
#include <iostream>

Player::Player(GameWindow *win, int x, int y) : Character(win, x, y, UP, 15, 10, 0.5, 1, 5, "asset/map.jpg", 25, false)
{
  //this->_sprite->_sprite.setTextureRect(sf::IntRect(0, 0, 24, 24));
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
}

void Player::up(GameWindow *win)
{
  collide(win->getCollision(), this->_x, this->_y - this->_speed);
  win->setView(this->_x, this->_y);
}

void Player::right(GameWindow *win)
{
  collide(win->getCollision(), this->_x + this->_speed, this->_y);
  win->setView(this->_x, this->_y);
}

void Player::down(GameWindow *win)
{
  collide(win->getCollision(), this->_x, this->_y + this->_speed);
  win->setView(this->_x, this->_y);
}

void Player::update(GameWindow *win, float time)
{
  size_t i;

  i = 0;
  std::cout << this->_x << " / " << this->_y << " --- " << this->_sprite->getX() << " / " << this->_sprite->getY() << std::endl;
  while (i < this->_projectiles.size())
    {
      if (this->_projectiles[i].update(win, time))
	this->_projectiles.erase(this->_projectiles.begin() + i);
      else
	i++;
    }
}

void Player::attack(GameWindow *win)
{
  (void)win;
  this->_projectiles.push_back(Projectile(this->_x, this->_y, this->_attack, this->_direction));
}

void Player::specialAttack(GameWindow *win)
{
  (void)win;
  this->_projectiles.push_back(Projectile(this->_x, this->_y, this->_attack, this->_direction));
}
