#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Character.hpp"

class Player : public Character
{
public:
  Player();
  Player(Player const&);
  ~Player();

  Player& operator=(Player const&);
};

#endif /* !PLAYER_HPP_ */
