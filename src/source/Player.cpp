#include "Player.hpp"

Player::Player(int x, int y) : Character(x, y, UP, 15, 10, 0.5, 1, 5, 25, false)
{
  this->_sprite = new wrap::Sprite(tMonk, 0, 0, false);
  (**this->_sprite).setTextureRect(sf::IntRect(0, 0, 24, 24));
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
  this->_projectiles.push_back(new Projectile(this->_x, this->_y, this->_attack, this->_direction));
}

void Player::specialAttack(GameWindow *win)
{
  (void)win;
  this->_projectiles.push_back(new Projectile(this->_x, this->_y, this->_attack, this->_direction));
}
