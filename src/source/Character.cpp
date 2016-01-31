#include "Character.hpp"
#include "GameWindow.hpp"
#include <iostream>

Character::Character(GameWindow *win, int x, int y, Direction direction, unsigned int hp,
		     unsigned int attack, float frequency, unsigned int speed,
		     unsigned int hitbox, const std::string &path, unsigned int range, bool fly) :
  _x((float)x),
  _y((float)y),
  _direction(direction),
  _hp(hp),
  _attack(attack),
  _frequency(frequency),
  _speed(speed),
  _hitbox(hitbox),
  _range(range),
  _sprite(new wrap::Sprite(path, x, y, true)),
  _fly(fly),
  _idx(0)
{
  win->_sprites.push_back(this->_sprite);
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
  _sprite(copy._sprite),
  _fly(copy._fly),
  _idx(copy._idx)
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
  this->_sprite = copy._sprite;
  this->_fly = copy._fly;
  this->_idx = copy._idx;
  return (*this);
}

bool Character::attack(Character &enemy)
{
  if (this->_hp <= 0)
    return (false);
  if ((float) (this->_cooldown.getElapsedTime()).asMilliseconds() / 1000 > this->_frequency)
    {
      if (this->_direction == LEFT)
	{
	  if (this->_x - (enemy._x + this->_hitbox) <= this->_range + this->_hitbox &&
	      this->_x - (enemy._x + (int)this->_hitbox) >= 0)
	    {
	      this->_cooldown.restart();
	      enemy.takeDamage(this->_attack);
	      return (true);
	    }
	}
      else if (this->_direction == UP)
	{
	  if (this->_y - (enemy._y + this->_hitbox) <= this->_range + this->_hitbox &&
	      this->_y - (enemy._y + (int)this->_hitbox) >= 0)
	    {
	      this->_cooldown.restart();
	      enemy.takeDamage(this->_attack);
	      return (true);
	    }
	}
      else if (this->_direction == RIGHT)
	{
	  if ((enemy._x - this->_hitbox) - this->_x <= this->_range + this->_hitbox &&
	      (enemy._x - (int)this->_hitbox) - this->_x >= 0)
	    {
	      this->_cooldown.restart();
	      enemy.takeDamage(this->_attack);
	      return (true);
	    }
	}
      else
	{
	  if ((enemy._y - this->_hitbox) - this->_y <= this->_range + this->_hitbox &&
	      (enemy._y - (int)this->_hitbox) - this->_y >= 0)
	    {
	      this->_cooldown.restart();
	      enemy.takeDamage(this->_attack);
	      return (true);
	    }
	}
    }
  return (false);
}

void Character::takeDamage(unsigned int damage)
{
  this->_hp = (damage >= this->_hp ? 0 : this->_hp - damage);
}

void Character::update(GameWindow *win, float time)
{
  if (this->_animation.getElapsedTime().asMilliseconds() > 200)
    {
      this->_animation.restart();
      this->_idx++;
      if (this->_idx > 2)
	this->_idx = 0;
    }
  if ((float) (this->_cooldown.getElapsedTime()).asMilliseconds() / 1000 > this->_frequency / 2)
    {
      if (!attack(win->getPlayer()))
	moveIA(win->getCollision(), win->getPlayer(), time);
    }
  this->_sprite->_sprite.setTextureRect(sf::IntRect(this->_idx * Al, (int)this->_direction * Al, Al, Al));
}

void Character::moveIA(sf::Image collision, const Character &player, float time)
{
  float	x;
  float x_tmp;
  float	y;
  float y_tmp;

  if (this->_hp <= 0)
    return ;
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout.precision(3);
  x = (float)player.getX() - this->_x;
  y = (float)player.getY() - this->_y;
  x_tmp = x;
  y_tmp = y;
  if (x_tmp < 0)
    x_tmp = -x_tmp;
  if (y < 0)
    y_tmp = -y_tmp;
  if (x + y == 0)
    return ;
  std::cout << this->_x << " ---> " << (float)(x / (x_tmp + y_tmp)) * this->_speed * time << std::endl;
  std::cout << this->_y << " ---> " << (float)(y / (x_tmp + y_tmp)) * this->_speed * time << std::endl << std::endl;
  collide(collision, this->_x + (float)(x / (x_tmp + y_tmp)) * this->_speed * time,
	  this->_y + (float)(y / (x_tmp + y_tmp)) * this->_speed * time);
  if (x_tmp > y_tmp)
    {
      if (x >= 0)
	this->_direction = RIGHT;
      else
	this->_direction = LEFT;
    }
  else
    {
      if (y >= 0)
	this->_direction = DOWN;
      else
	this->_direction = UP;
    }
}

void Character::collide(sf::Image collision, float newX, float newY)
{
  if (this->_x < newX)
    {
      while (this->_x < newX && newX < collision.getSize().x)
	{
	  if (collision.getPixel(this->_x + (int)this->_hitbox + 1, this->_y) != sf::Color::Red)
	    setX(this->_x + 0.1);
	  else
	    break ;
	}
    }
  else
    {
      while (this->_x > newX && newX >= 0)
	{
	  if (collision.getPixel(this->_x - (int)this->_hitbox - 1, this->_y) != sf::Color::Red)
	    setX(this->_x - 0.1);
	  else
	    break ;
	}
    }
  if (this->_y < newY)
    {
      while (this->_y < newY && newY < collision.getSize().y)
	{
	  if (collision.getPixel(this->_x, this->_y + (int)this->_hitbox + 1) != sf::Color::Red)
	    setY(this->_y + 0.1);
	  else
	    break ;
	}
    }
  else
    {
      while (this->_y > newY && newY >= 0)
	{
	  if (collision.getPixel(this->_x, this->_y - (int)this->_hitbox - 1) != sf::Color::Red)
	    setY(this->_y - 0.1);
	  else
	    break ;
	}
    }
}

int Character::getX() const
{
  return (this->_x);
}

void Character::setX(float x)
{
  this->_x = x;
  this->_sprite->setPos(this->_x, this->_y);
}

int Character::getY() const
{
  return (this->_y);
}

void Character::setY(float y)
{
  this->_y = y;
  this->_sprite->setPos(this->_x, this->_y);
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

bool Character::getFly() const
{
  return (this->_fly);
}

void Character::setFly(bool newFly)
{
  this->_fly = newFly;
}
