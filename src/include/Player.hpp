#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Character.hpp"

class Player : public Character
{
public:
  void left();
  void up();
  void right();
  void down();
public:
  Player(int, int);
  Player(Player const&);
  ~Player();

  Player& operator=(Player const&);

  void attack(GameWindow *);
  void specialAttack(GameWindow *);
};

void (Player:: *move[4])() =
{
  &Player::left,
  &Player::up,
  &Player::right,
  &Player::down
};

#endif /* !PLAYER_HPP_ */
