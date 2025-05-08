#ifndef PLATFORMERSFML_MONSTER_H
#define PLATFORMERSFML_MONSTER_H

#include "Entities.h"

class Monster : public Entities
{
 public:
  void monsterMap1Init(int i);
  void updateMonsterAnimation(int player_pos);
  void monsterHitBox();

 private:
  sf::Texture monster_texture;
  sf::String monster_texture_file = "Data/Images/Enemy/Assets.png";
  MovementStates move_state {MovementStates::IDLE};
  sf::RectangleShape monster_hit_box;



  //Getters && Setters
 public:
  const sf::RectangleShape& getMonsterHitBox() const;
  MovementStates getMoveState() const;
  void setMoveState(MovementStates moveState);
};

#endif // PLATFORMERSFML_MONSTER_H