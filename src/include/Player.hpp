#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include "Character.hpp"

class Player : public Character
{
public:
  void left(GameWindow *);
  void up(GameWindow *);
  void right(GameWindow *);
  void down(GameWindow *);
public:
  Player(int, int);
  Player(Player const&);
  ~Player();

  Player& operator=(Player const&);

  void update(GameWindow *, float);
  void attack(GameWindow *);
  void specialAttack(GameWindow *);

private:
  std::vector<Projectile> _projectiles;
};

#endif /* !PLAYER_HPP_ */
