#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_


class Character
{
public:
  Character();
  Character(Character const&);
  ~Character();

  Character& operator=(Character const&);

  unsigned int getHp() const;
  void setHp(unsigned int);
  unsigned int getAttack() const;
  void setAttack(unsigned int);
  float getFrequence() const;
  void setFrequence(float);
  float getSpeed() const;
  void setSpeed(float);
  bool getFly() const;
  void setFly(bool);

protected:
  unsigned int _hp;
  unsigned int _attack;
  float _frequence;
  float _speed;
  bool _fly;
};

#endif /* !CHARACTER_HPP_ */
