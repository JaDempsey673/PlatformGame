//
// Created by TheRe on 08/03/2023.
//

#include "Player.h"
#include "Monster.h"
#include <iostream>

void Player::playerInit()
{
  if (!player_texture.loadFromFile(player_texture_file))
  {
    std::cout << "Failed to load texture: player";
  }

  initialiseSprite(player_texture);
  getSprite()->setPosition(250,480);
  getSprite()->setScale(3,3);
  getSprite()->setTextureRect(current_frame);
  setMoveState(MovementStates::IDLE);
  setDead(false);

  initialiseAnimation();
}

void Player::updatePlayerAnimations()
{
  getSprite()->setOrigin(getSprite()->getLocalBounds().width / 2, 0);

  if (move_state == MovementStates::IDLE)
  {
    if (timer.getElapsedTime().asSeconds() >= 0.15)
    {
      current_frame.top = 0;
      current_frame.left += 50;
      if (current_frame.left >= 200)
      {
        current_frame.left = 0;
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
  else if (move_state == MovementStates::MOVE_RIGHT)
  {
    if (getTimer().getElapsedTime().asSeconds() >= 0.10)
    {
      current_frame.top = 37;
      current_frame.left += 50;

      if (current_frame.left >= 350)
      {
        current_frame.left = 50;
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
  else if (move_state == MovementStates::MOVE_LEFT)
  {
    if (getTimer().getElapsedTime().asSeconds() >= 0.10)
    {
      current_frame.top = 37;
      current_frame.left += 50;

      if (getSprite()->getScale().x == 3.f)
      {
        getSprite()->setScale(-3.f, 3.f);
      }

      if (current_frame.left >= 350)
      {
        current_frame.left = 50;
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
  else if (move_state == MovementStates::JUMPING)
  {
    if (getTimer().getElapsedTime().asSeconds() >= 0.10)
    {
      if (getVelocity().y <= -(getHeight() * 0.25))
      {
        current_frame.top  = 73;
        current_frame.left = 100;
      }
      else if ((-(getHeight() * 0.25) <= getVelocity().y) && (getVelocity().y <= 0))
      {
        current_frame.top  = 74;
        current_frame.left = 150;
      }
      else if ((0 <= getVelocity().y) && (getVelocity().y <= (getHeight() * 0.25)))
      {
        current_frame.top  = 111;
        current_frame.left = 50;
      }
      else if (getVelocity().y >= (getHeight() * 0.25))
      {
        current_frame.top  = 111;
        current_frame.left = 100;
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
  else if (move_state == MovementStates::DYING)
  {
    if (getTimer().getElapsedTime().asSeconds() >= 0.20)
    {
      if (current_frame.top != 333)
      {
        current_frame.top  = 333;
        current_frame.left = 0;
      }

      current_frame.left += 50;

      if (current_frame.left >= 150)
      {
        setDead(true);
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
  else if (move_state == MovementStates::ATTACKING_ONE)
  {
    if (getTimer().getElapsedTime().asSeconds() >= 0.10)
    {
      current_frame.top = 222;
      current_frame.left += 50;

      if (current_frame.left >= 300)
      {
        setAttacking(false);

        if (isJumped())
        {
          move_state = MovementStates::JUMPING;
        }
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
}

void Player::playerHitBox()
{
  if (getSprite()->getScale() == sf::Vector2f(3.f, 3.f))
  {
    hit_box_frame = sf::IntRect(getSprite()->getPosition().x - 25,
                                getSprite()->getPosition().y + 16,
                                getSprite()->getLocalBounds().width,
                                getSprite()->getLocalBounds().height * 2.3);
  }
  else if (getSprite()->getScale() == sf::Vector2f(-3.f, 3.f))
  {
    hit_box_frame = sf::IntRect(getSprite()->getPosition().x - 25,
                                getSprite()->getPosition().y + 16,
                                getSprite()->getLocalBounds().width,
                                getSprite()->getLocalBounds().height * 2.3);
  }

  player_hit_box.setSize(sf::Vector2f(hit_box_frame.width,
                                      hit_box_frame.height));
  player_hit_box.setPosition(sf::Vector2f(hit_box_frame.left,
                                          hit_box_frame.top));

}

void Player::groundCheck()
{
  if (getSprite()->getScale() == sf::Vector2f(3.f, 3.f))
  {
    ground_check_frame = sf::IntRect(getSprite()->getPosition().x - 25,
                                getSprite()->getPosition().y + 100,
                                getSprite()->getLocalBounds().width,
                                getSprite()->getLocalBounds().height / 6);
  }
  else if (getSprite()->getScale() == sf::Vector2f(-3.f, 3.f))
  {
    ground_check_frame = sf::IntRect(getSprite()->getPosition().x - 25,
                                getSprite()->getPosition().y + 100,
                                getSprite()->getLocalBounds().width,
                                getSprite()->getLocalBounds().height / 6);
  }

  ground_check.setSize(sf::Vector2f(ground_check_frame.width,
                                    ground_check_frame.height));
  ground_check.setPosition(sf::Vector2f(ground_check_frame.left,
                                        ground_check_frame.top));

}

void Player::attackHitBox()
{
  if (isAttacking() == 1)
  {
    if (getSprite()->getScale() == sf::Vector2f(3.f, 3.f))
    {
      attack_one_hit_box.setPosition(
        getSprite()->getPosition().x - 26, getSprite()->getPosition().y - 2);
      attack_one_hit_box.setRadius(50);
    }
    else if (getSprite()->getScale() == sf::Vector2f(-3.f, 3.f))
    {
      attack_one_hit_box.setPosition(
        getSprite()->getPosition().x - 75, getSprite()->getPosition().y - 2);
      attack_one_hit_box.setRadius(50);
    }
  }
}



//Getters && Setters
Entities::MovementStates Player::getMoveState() const
{
  return move_state;
}
void Player::setMoveState(Entities::MovementStates moveState)
{
  move_state = moveState;
}
const sf::RectangleShape& Player::getPlayerHitBox() const
{
  return player_hit_box;
}
const sf::CircleShape& Player::getAttackOneHitBox() const
{
  return attack_one_hit_box;
}
const sf::RectangleShape& Player::getGroundCheck() const
{
  return ground_check;
}
