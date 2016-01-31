#include "Projectile.hpp"
#include "GameWindow.hpp"
#include <iostream>

Projectile::Projectile(GameWindow *win, int x, int y, int damage, Direction direction) :
  _baseX((float)x),
  _baseY((float)y),
  _x((float)x),
  _y((float)y),
  _damage(damage),
  _speed(100),
  _range(0),
  _sprite(new wrap::Sprite(tBall, x, y, false))
{
  if (direction == LEFT)
    this->_angle = 180;
  else if (direction == UP)
    this->_angle = 90;
  else if (direction == RIGHT)
    this->_angle = 0;
  else
    this->_angle = 270;
  win->_sprites.push_back(this->_sprite);
}

Projectile::Projectile(GameWindow *win, int x, int y, int damage, Direction direction, int range) :
  _baseX((float)x),
  _baseY((float)y),
  _x((float)x),
  _y((float)y),
  _damage(damage),
  _speed(100),
  _range(range),
  _sprite(new wrap::Sprite(tBall, x, y, false))
{
  if (direction == LEFT)
    this->_angle = 180;
  else if (direction == UP)
    this->_angle = 90;
  else if (direction == RIGHT)
    this->_angle = 0;
  else
    this->_angle = 270;
  this->_angle += (rand() % 120 - 60);
  if (this->_angle < 0)
    this->_angle += 360;
  win->_sprites.push_back(this->_sprite);
}

Projectile::Projectile(Projectile const& copy) :
  _baseX(copy._baseX),
  _baseY(copy._baseY),
  _x(copy._x),
  _y(copy._y),
  _damage(copy._damage),
  _speed(copy._speed),
  _range(copy._range),
  _angle(copy._angle),
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
  this->_angle = copy._angle;
  this->_sprite = copy._sprite;
  return (*this);
}

bool Projectile::update(GameWindow *win, float time)
{
  if (move(win, time))
    return (true);
  return (win->checkProjectile(*this));
}

bool Projectile::move(GameWindow *win, float time)
{
  int x;
  int y;

  if (this->_angle >= 0 && this->_angle < 90)
    {
      std::cout << this->_x << " / " << this->_x + time * this->_speed * ((90 - (float)this->_angle) / 90) << " --- " << ((90 - (float)this->_angle) / 90) << std::endl;
      setX(this->_x + time * this->_speed * ((90 - (float)this->_angle) / 90));
      setY(this->_y - time * this->_speed * ((float)this->_angle / 90));
    }
  else if (this->_angle < 180)
    {
      setX(this->_x - time * this->_speed * (((float)this->_angle - 90) / 90));
      setY(this->_y - time * this->_speed * (-1 * ((float)this->_angle - 180) / 90));
    }
  else if (this->_angle < 270)
    {
      setX(this->_x - time * this->_speed * (-1 * ((float)this->_angle - 270) / 90));
      setY(this->_y + time * this->_speed * (((float)this->_angle - 180) / 90));
    }
  else
    {
      setX(this->_x + time * this->_speed * (((float)this->_angle - 270) / 90));
      setY(this->_y + time * this->_speed * (-1 * ((float)this->_angle - 360) / 90));
    }
  if (this->_range == 0)
    {
      if (this->_x < 0 || this->_y < 0 || this->_x > win->getWidth() || this->_y > win->getHeight())
	return (true);
    }
  else
    {
      x = this->_x - this->_baseX;
      if (x < 0)
	x = -x;
      y = this->_y - this->_baseY;
      if (y < 0)
	y = -y;
      if (x + y >= this->_range)	
	return (true);
    }
  return (false);
}

int Projectile::getX() const
{
  return (this->_x);
}

void Projectile::setX(float newX)
{
  this->_x = newX;
  this->_sprite->setPos(this->_x, this->_y);
}

int Projectile::getY() const
{
  return (this->_y);
}

void Projectile::setY(float newY)
{
  this->_y = newY;
  this->_sprite->setPos(this->_x, this->_y);
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
