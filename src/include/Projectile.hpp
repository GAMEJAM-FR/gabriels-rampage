#ifndef PROJECTILE_HPP_
# define PROJECTILE_HPP_

# include "Constants.hpp"
# include "Asset.hpp"

class GameWindow;

class Projectile
{
public:
  Projectile(GameWindow *, int, int, int, Direction);
  Projectile(GameWindow *, int, int, int, Direction, int);
  Projectile(Projectile const&);
  ~Projectile();

  Projectile& operator=(Projectile const&);

  bool update(GameWindow *, float);
private:
  bool move(GameWindow *, float);

public:
  int getX() const;
  void setX(float);
  int getY() const;
  void setY(float);
  int getDamage() const;
  void setDamage(int);
  float getSpeed() const;
  void setSpeed(float);
  
private:
  float _baseX;
  float _baseY;
  float _x;
  float _y;
  int _damage;
  float _speed;
  int _range;
  int _angle;
public:
  wrap::Sprite *_sprite;
};

#endif /* !PROJECTILE_HPP_ */
