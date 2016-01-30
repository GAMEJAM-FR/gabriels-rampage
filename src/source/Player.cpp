#include "Player.hpp"
#include <iostream>
Player::Player(int x, int y) : Character(x, y, Character::UP, 15, 10, 0.5, 1, 5, 25, false)
{
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

void Player::attack(GameWindow *win)
{
  (void)win;
}

void Player::specialAttack(GameWindow *win)
{
  (void)win;
}
