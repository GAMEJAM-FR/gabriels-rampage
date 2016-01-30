#include "Projectile.hpp"

Projectile::Projectile(int x, int y, int damage, Direction direction) :
  _baseX((float)x),
  _baseY((float)y),
  _x((float)x),
  _y((float)y),
  _damage(damage),
  _direction(direction)
{
  this->_range = 0;
  this->_speed = 100;
}

Projectile::Projectile(int x, int y, int damage, Direction direction, int range) :
  _baseX((float)x),
  _baseY((float)y),
  _x((float)x),
  _y((float)y),
  _damage(damage),
  _direction(direction),
  _range(range)
{
  this->_speed = 100;
}

Projectile::Projectile(Projectile const& copy) :
  _baseX(copy._baseX),
  _baseY(copy._baseY),
  _x(copy._x),
  _y(copy._y),
  _damage(copy._damage),
  _speed(copy._speed),
  _direction(copy._direction),
{
  
}

Projectile::~Projectile()
{

}

Projectile& Projectile::operator=(Projectile const& copy)
{
  this->_baseX = copy._baseX;
  this->_baseY = copy._baseY;
  this->_x = copy._x;
  this->_y = copy._y;
  this->_damage = copy._damage;
  this->_speed = copy._speed;
  this->_direction = copy._direction;
  return (*this);
}

bool Projectile::update(GameWindow *win, float time)
{
  if (move(time))
    return (true);
  return (win->checkProjectile(this));
}

bool Projectile::move(float time)
{
  if (this->_direction == LEFT)
    this->_x -= this->_direction * this->_time;
  else if (this->_direction == UP)
    this->_y -= this->_direction * this->_time;
  else if (this->_direction == RIGHT)
    this->_x += this->_direction * this->_time;
  else
    this->_y += this->_direction * this->_time;
  if ((this->_x - this->_baseX) + (this->_y - this->_baseY) >= this->_range)
    return (true);
  return (false);
}

int Projectile::getX() const
{
  return (this->_x);
}

void Projectile::setX(int newX)
{
  this->_x = newX;
}

int Projectile::getY() const
{
  return (this->_y);
}

void Projectile::setY(int newY)
{
  this->_y = newY;
}

int Projectile::getDamage() const
{
  return (this->_damage);
}

void Projectile::setDamage(int newDamage)
{
  this->_damage = newDamage;
}

float Projectile::getSpeed() const
{
  return (this->_speed);
}

void Projectile::setSpeed(float newSpeed)
{
  this->_speed = newSpeed;
}

Direction Projectile::getDirection() const
{
  return (this->_direction);
}

void Projectile::setDirection(Direction newDirection)
{
  this->_direction = newDirection;
}
