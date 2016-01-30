#ifndef PROJECTILE_HPP_
# define PROJECTILE_HPP_

# include "Constants.hpp"

class Projectile
{
public:
  Projectile(int, int, int, Direction);
  Projectile(int, int, int, Direction, int);
  Projectile(Projectile const&);
  ~Projectile();

  Projectile& operator=(Projectile const&);

  bool update(float);
  
  int getX() const;
  void setX(int);
  int getY() const;
  void setY(int);
  int getDamage() const;
  void setDamage(int);
  float getSpeed() const;
  void setSpeed(float);
  Direction getDirection() const;
  void setDirection(Direction);

private:
  float _baseX;
  float _baseY;
  float _x;
  float _y;
  int _damage;
  float _speed;
  int _range;
  Direction _direction;

  bool move(float);
};

#endif /* !PROJECTILE_HPP_ */
