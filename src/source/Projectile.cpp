#include "Projectile.hpp"
#include "GameWindow.hpp"

Projectile::Projectile(int x, int y, int damage, Direction direction) :
  _baseX((float)x),
  _baseY((float)y),
  _x((float)x),
  _y((float)y),
  _damage(damage),
  _speed(100),
  _range(0),
  _direction(direction),
  _sprite(tBall, x, y, false)
{

}

Projectile::Projectile(int x, int y, int damage, Direction direction, int range) :
  _baseX((float)x),
  _baseY((float)y),
  _x((float)x),
  _y((float)y),
  _damage(damage),
  _speed(100),
  _range(range),
  _direction(direction),
  _sprite(tBall, x, y, false)
{

}

Projectile::Projectile(Projectile const& copy) :
  _baseX(copy._baseX),
  _baseY(copy._baseY),
  _x(copy._x),
  _y(copy._y),
  _damage(copy._damage),
  _speed(copy._speed),
  _range(copy._range),
  _direction(copy._direction),
  _sprite(copy._sprite)
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
  this->_range = copy._range;
  this->_direction = copy._direction;
  this->_sprite = copy._sprite;
  return (*this);
}

bool Projectile::update(GameWindow *win, float time)
{
  if (move(time))
    return (true);
  return (win->checkProjectile(*this));
}

bool Projectile::move(float time)
{
  if (this->_direction == LEFT)
    setX(this->_x - this->_direction * time);
  else if (this->_direction == UP)
    setY(this->_y - this->_direction * time);
  else if (this->_direction == RIGHT)
    setX(this->_x + this->_direction * time);
  else
    setY(this->_y + this->_direction * time);
  /*if (this->_range == 0)
    {
      if (this->_x < 0 || this->_y < 0 || this->_x > win->getWidth() || this->_y > win->getHeight())
	return (true);
    }
    else */if ((this->_x - this->_baseX) + (this->_y - this->_baseY) >= this->_range)
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
  this->_sprite.setPos(this->_x, this->_y);
}

int Projectile::getY() const
{
  return (this->_y);
}

void Projectile::setY(int newY)
{
  this->_y = newY;
  this->_sprite.setPos(this->_x, this->_y);
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
