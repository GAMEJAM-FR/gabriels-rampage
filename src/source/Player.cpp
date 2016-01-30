#include "Player.hpp"

Player::Player(int x, int y) : Character(x, y, Character::UP, 15, 10, 0.5, 15, 5, 25, false)
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

void Player::left()
{
  collide(this->_x - this->_speed, this->_y);
}

void Player::up()
{
  collide(this->_x, this->_y - this->_speed);
}

void Player::right()
{
  collide(this->_x + this->_speed, this->_y);
}

void Player::down()
{
  collide(this->_x, this->_y + this->_speed);
}

void Player::attack(GameWindow *win)
{
  (void)win;
}

void Player::specialAttack(GameWindow *win)
{
  (void)win;
}
