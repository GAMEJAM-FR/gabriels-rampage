#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Character.hpp"

class Player : public Character
{
private:
  void left(int, int);
  void up(int, int);
  void right(int, int);
  void down(int, int);
public:
  void (Player:: *move[4])(int, int) =
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
};

#endif /* !PLAYER_HPP_ */
