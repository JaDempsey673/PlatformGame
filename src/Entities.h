//
// Created by TheRe on 08/03/2023.
//

#ifndef PLATFORMERSFML_ENTITIES_H
#define PLATFORMERSFML_ENTITIES_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class Entities
{
 public:
  void initialiseSprite(sf::Texture &Texture);
  void initialiseAnimation();

  enum class MovementStates
  {
    IDLE = 0,
    MOVE_LEFT = 1,
    MOVE_RIGHT = 2,
    JUMPING = 3,
    DYING = 4,
    ATTACKING_ONE = 5,
    DEAD = 6,
  };

 private:
  sf::Sprite* sprite = nullptr;
  Vector2 velocity = Vector2(0,0);
  float gravity = 9.8;
  bool moving = false;
  int attacking = 0;
  int height = -300;
  bool jumped = false;
  bool dead = false;

 protected:
  sf::Clock timer;
  sf::IntRect current_frame = sf::IntRect(0,0,50,40);
  sf::IntRect hit_box_frame = sf::IntRect (0,0,0,0);



  //Getters & Setters
 public:
  bool isJumped() const;
  void setJumped(bool jumped);
  sf::Sprite* getSprite() const;
  float getGravity() const;
  const Vector2& getVelocity() const;
  void setVelocity(const Vector2& velocity);
  bool isMoving() const;
  void setMoving(bool moving);
  const sf::Clock& getTimer() const;
  int getHeight() const;
  int isAttacking() const;
  void setAttacking(int attacking);
  void setCurrentFrameLeft(int left);
  bool isDead() const;
  void setDead(bool dead);
};

#endif // PLATFORMERSFML_ENTITIES_H