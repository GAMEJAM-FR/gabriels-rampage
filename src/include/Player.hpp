#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Character.hpp"

class Player : public Character
{
private:
  void left(unsigned int);
  void up(unsigned int);
  void right(unsigned int);
  void down(unsigned int);
public:
  void (Player:: *move[4])(unsigned int) =
  {
    &Player::left,
    &Player::up,
    &Player::right,
    &Player::down
  };
public:
  Player();
  Player(Player const&);
  ~Player();

  Player& operator=(Player const&);

  void attack(GameWindow *&);
  void specialAttack(GameWindow *&);
};

#endif /* !PLAYER_HPP_ */
