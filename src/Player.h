//
// Created by TheRe on 08/03/2023.
//

#ifndef PLATFORMERSFML_PLAYER_H
#define PLATFORMERSFML_PLAYER_H

#include "Entities.h"
#include "Monster.h"
#include "SFML/Graphics.hpp"

class Player : public Entities
{
 public:
  void playerInit();
  void updatePlayerAnimations();
  void playerHitBox();
  void groundCheck();
  void attackHitBox();

 private:
  sf::Texture player_texture;
  sf::String player_texture_file = "Data/Images/Player/adventurer-v1.5-Sheet.png";
  MovementStates move_state {MovementStates::IDLE};
  sf::RectangleShape player_hit_box;
  sf::CircleShape attack_one_hit_box;
  sf::IntRect ground_check_frame;
  sf::RectangleShape ground_check;


  //Getters && Setters
 public:
  MovementStates getMoveState() const;
  void setMoveState(MovementStates moveState);
  const sf::RectangleShape& getPlayerHitBox() const;
  const sf::CircleShape& getAttackOneHitBox() const;
  const sf::RectangleShape& getGroundCheck() const;
};

#endif // PLATFORMERSFML_PLAYER_H
