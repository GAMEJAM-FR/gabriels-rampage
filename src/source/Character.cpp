#include "Character.hpp"

Character::Character(int x, int y, Character::Direction direction, unsigned int hp,
		     unsigned int attack, float frequency, unsigned int speed,
		     unsigned int hitbox, unsigned int range, bool fly) :
  _x(x),
  _y(y),
  _direction(direction),
  _hp(hp),
  _attack(attack),
  _frequency(frequency),
  _speed(speed),
  _hitbox(hitbox),
  _range(range),
  _fly(fly)
{

}

Character::Character(Character const& copy) :
  _x(copy._x),
  _y(copy._y),
  _direction(copy._direction),
  _hp(copy._hp),
  _attack(copy._attack),
  _frequency(copy._frequency),
  _speed(copy._speed),
  _hitbox(copy._hitbox),
  _range(copy._range),
  _fly(copy._fly)
{
  
}

Character::~Character()
{

}

Character& Character::operator=(Character const& copy)
{
  this->_hp = copy._hp;
  this->_attack = copy._attack;
  this->_frequency = copy._frequency;
  this->_speed = copy._speed;
  this->_hitbox = copy._hitbox;
  this->_range = copy._range;
  this->_sprites = copy._sprites;
  this->_fly = copy._fly;
  return (*this);
}

void Character::attack(Character*& enemy)
{
  //Add frequency
  if (this->_direction == LEFT)
    {
      if (this->_x - (enemy->_x + this->_hitbox) <= this->_range + this->_hitbox &&
	  this->_x - (enemy->_x + (int)this->_hitbox) >= 0)
	enemy->takeDamage(this->_attack);
    }
  else if (this->_direction == UP)
    {
      if (this->_y - (enemy->_y + this->_hitbox) <= this->_range + this->_hitbox &&
	  this->_y - (enemy->_y + (int)this->_hitbox) >= 0)
	enemy->takeDamage(this->_attack);
    }
  else if (this->_direction == RIGHT)
    {
      if ((enemy->_x - this->_hitbox) - this->_x <= this->_range + this->_hitbox &&
	  (enemy->_x - (int)this->_hitbox) - this->_x >= 0)
	enemy->takeDamage(this->_attack);
    }
  else
    {
      if ((enemy->_y - this->_hitbox) - this->_y <= this->_range + this->_hitbox &&
	  (enemy->_y - (int)this->_hitbox) - this->_y >= 0)
	enemy->takeDamage(this->_attack);
    }
}

void Character::takeDamage(unsigned int damage)
{
  this->_hp = (damage >= this->_hp ? 0 : this->_hp - damage);
}

void Character::update()
{
  
}

int Character::getX() const
{
  return (this->_x);
}

void Character::setX(int x)
{
  this->_x = x;
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

float Character::getFrequency() const
{
  return (this->_frequency);
}

void Character::setFrequency(float newFrequency)
{
  this->_frequency = newFrequency;
}

unsigned int Character::getSpeed() const
{
  return (this->_speed);
}

void Character::setSpeed(unsigned int newSpeed)
{
  this->_speed = newSpeed;
}

unsigned int Character::getHitbox() const
{
  return (this->_hitbox);
}

void Character::setHitbox(unsigned int newHitbox)
{
  this->_hitbox = newHitbox;
}

unsigned int Character::getRange() const
{
  return (this->_range);
}

void Character::setRange(unsigned int newRange)
{
  this->_range = newRange;
}

std::vector<sf::Sprite *> Character::getSprites() const
{
  return (this->_sprites);
}

void Character::setSprites(std::vector<sf::Sprite *> newSprites)
{
  this->_sprites = newSprites;
}

bool Character::getFly() const
{
  return (this->_fly);
}

void Character::setFly(bool newFly)
{
  this->_fly = newFly;
}
