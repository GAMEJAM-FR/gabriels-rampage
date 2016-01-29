#include "Character.hpp"

Character::Character()
  : _hp(1),
    _attack(1),
    _frequence(1),
    _speed(10),
    _fly(false)
{
  
}

Character::Character(Character const& copy)
{
  this->_hp = copy._hp;
  this->_attack = copy._attack;
  this->_frequence = copy._frequence;
  this->_speed = copy._speed;
  this->_fly = copy._fly;
}

Character::~Character()
{

}

Character& Character::operator=(Character const& copy)
{
  this->_hp = copy._hp;
  this->_attack = copy._attack;
  this->_frequence = copy._frequence;
  this->_speed = copy._speed;
  this->_fly = copy._fly;
  return (*this);
}

unsigned int Character::getHp() const
{
  return (this->_hp);
}

void Character::setHp(unsigned int newHp)
{
  this->_hp = newHp;
}

unsigned int Character::getAttack() const
{
  return (this->_attack);
}

void Character::setAttack(unsigned int newAttack)
{
  this->_attack = newAttack;
}

float Character::getFrequence() const
{
  return (this->_frequence);
}

void Character::setFrequence(float newFrequence)
{
  this->_frequence = newFrequence;
}

float Character::getSpeed() const
{
  return (this->_speed);
}

void Character::setSpeed(float newSpeed)
{
  this->_speed = newSpeed;
}

bool Character::getFly() const
{
  return (this->_fly);
}

void Character::setFly(bool newFly)
{
  this->_fly = newFly;
}
