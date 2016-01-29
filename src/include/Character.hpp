#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include <SFML/Graphics.hpp>
# include <vector>

class Character
{
public:
  Character(unsigned int hp = 1, unsigned int attack = 1, float frequence = 1, unsigned int speed = 10,
	    unsigned int hitbox = 5, unsigned int range = 5, bool fly = false);
  Character(Character const&);
  ~Character();

  Character& operator=(Character const&);

  unsigned int getHp() const;
  void setHp(unsigned int);
  unsigned int getAttack() const;
  void setAttack(unsigned int);
  float getFrequence() const;
  void setFrequence(float);
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
  unsigned int _hp;
  unsigned int _attack;
  float _frequence;
  unsigned int _speed;
  unsigned int _hitbox;
  unsigned int _range;
  std::vector<sf::Sprite *> _sprites;
  bool _fly;
};

#endif /* !CHARACTER_HPP_ */
