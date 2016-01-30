#include "Player.hpp"

Player::Player() : Character(0, 0, Character::UP, 15, 10, 0.5, 15, 5, 25, false)
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
