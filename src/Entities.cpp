//
// Created by TheRe on 08/03/2023.
//

#include "Entities.h"
#include <iostream>

void Entities::initialiseSprite(sf::Texture &texture)
{
  sprite = new sf::Sprite();
  sprite->setTexture(texture);
}

void Entities::initialiseAnimation()
{
  timer.restart();
}



//Getters & Setters
bool Entities::isJumped() const
{
  return jumped;
}
void Entities::setJumped(bool jumped)
{
  Entities::jumped = jumped;
}
sf::Sprite* Entities::getSprite() const
{
  return sprite;
}
const Vector2& Entities::getVelocity() const
{
  return velocity;
}
void Entities::setVelocity(const Vector2& velocity)
{
  Entities::velocity = velocity;
}
float Entities::getGravity() const
{
  return gravity;
}
bool Entities::isMoving() const
{
  return moving;
}
void Entities::setMoving(bool moving)
{
  Entities::moving = moving;
}
const sf::Clock& Entities::getTimer() const
{
  return timer;
}
int Entities::getHeight() const
{
  return height;
}
int Entities::isAttacking() const
{
  return attacking;
}
void Entities::setAttacking(int attacking)
{
  Entities::attacking = attacking;
}
void Entities::setCurrentFrameLeft(int left)
{
  current_frame.left = left;
}
bool Entities::isDead() const
{
  return dead;
}
void Entities::setDead(bool dead)
{
  Entities::dead = dead;
}
