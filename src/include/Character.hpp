#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include <SFML/Graphics.hpp>
# include <vector>

class Character
{
protected:
  enum Direction
    {
      LEFT,
      UP,
      RIGHT,
      DOWN
    };
  
public:
  Character(int x, int y, Direction _direction = DOWN, unsigned int hp = 1,
	    unsigned int attack = 1, float frequency = 1, unsigned int speed = 10,
	    unsigned int hitbox = 5, unsigned int range = 5, bool fly = false);
  Character(Character const&);
  ~Character();

  Character& operator=(Character const&);

  virtual void attack(Character *&);
  void takeDamage(unsigned int);
  virtual void update(GameWindow *, float);
  
  int getX() const;
  void setX(int);
  int getY() const;
  void setY(int);
  unsigned int getHp() const;
  void setHp(unsigned int);
  unsigned int getAttack() const;
  void setAttack(unsigned int);
  float getFrequency() const;
  void setFrequency(float);
  unsigned int getSpeed() const;
  void setSpeed(unsigned int);
  unsigned int getHitbox() const;
  void setHitbox(unsigned int);
  unsigned int getRange() const;
  void setRange(unsigned int);
  std::vector<sf::Sprite *> getSprites() const;
  void setSprites(std::vector<sf::Sprite *>);
  bool getFly() const;
  void setFly(bool);

protected:
  int _x;
  int _y;
  Direction _direction;
  unsigned int _hp;
  unsigned int _attack;
  float _frequency;
  unsigned int _speed;
  unsigned int _hitbox;
  unsigned int _range;
  std::vector<sf::Sprite *> _sprites;
  bool _fly;
  sf::Clock _cooldown;
};

#endif /* !CHARACTER_HPP_ */
