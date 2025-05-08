
#include "Monster.h"
#include <iostream>

void Monster::monsterMap1Init(int i)
{
  current_frame.width = 50;
  current_frame.height = 75;
  current_frame.top = 655;
  current_frame.left = 725;

  setMoveState(MovementStates::IDLE);

  if (!monster_texture.loadFromFile(monster_texture_file))
  {
    std::cout << "Failed to load font: monster";
  }

  initialiseSprite(monster_texture);
  getSprite()->setScale(1.75,1.75);
  getSprite()->setTextureRect(current_frame);
  initialiseAnimation();

  switch(i)
  {
    case 0:
      getSprite()->setPosition(845,356);
      break;

    case 1:
      getSprite()->setPosition(1730,452);
      break;

    case 2:
      getSprite()->setPosition(2281,324);
      break;

    case 3:
      getSprite()->setPosition(2892,196);
      break;

    case 4:
      getSprite()->setPosition(3558,373);
      break;

    case 5:
      getSprite()->setPosition(4340,388);
      break;

    case 6:
      getSprite()->setPosition(5271,132);
      break;

    case 7:
      getSprite()->setPosition(5626,21);
      break;

    default:
      break;
  }
}

void Monster::updateMonsterAnimation(int player_pos)
{
  getSprite()->setOrigin(getSprite()->getLocalBounds().width / 2, 0);


  if (move_state != MovementStates::DYING)
  {
    if (player_pos < getSprite()->getPosition().x)
    {
      getSprite()->setScale(-1.75, 1.75);
    }
    else
    {
      getSprite()->setScale(1.75, 1.75);
    }
  }

  if (move_state == MovementStates::IDLE)
  {
    if (timer.getElapsedTime().asSeconds() >= 0.25)
    {
      current_frame.top = 663;
      current_frame.left += 500;
      if (current_frame.left >= 2500)
      {
        current_frame.left = 725;
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
  if (move_state == MovementStates::DYING)
  {
    if (timer.getElapsedTime().asSeconds() >= 0.3)
    {
      if (current_frame.top != 1596)
      {
        current_frame.top = 1596;
        current_frame.left = 225;
      }

      current_frame.left += 500;

      if (current_frame.left == 1225)
      {
        if (getSprite()->getScale() == sf::Vector2f(1.75, 1.75))
        {
          getSprite()->setPosition(
            getSprite()->getPosition().x + 10,
            getSprite()->getPosition().y + 10);
        }
        if (getSprite()->getScale() == sf::Vector2f(-1.75, 1.75))
        {
          getSprite()->setPosition(
            getSprite()->getPosition().x - 10,
            getSprite()->getPosition().y + 10);
        }
      }

      else if (current_frame.left == 1725)
      {
        if (getSprite()->getScale() == sf::Vector2f(1.75, 1.75))
        {
          getSprite()->setPosition(
            getSprite()->getPosition().x + 20,
            getSprite()->getPosition().y + 20);
        }        if (getSprite()->getScale() == sf::Vector2f(-1.75, 1.75))
        {
          getSprite()->setPosition(
            getSprite()->getPosition().x - 20,
            getSprite()->getPosition().y + 20);
        }
      }

      else if (current_frame.left == 2725)
      {
        current_frame.left = 2225;
      }

      timer.restart();
      getSprite()->setTextureRect(current_frame);
    }
  }
}

void Monster::monsterHitBox()
{
  monster_hit_box.setSize(sf::Vector2f(getSprite()->getGlobalBounds().width - 40,
                                       getSprite()->getGlobalBounds().height - 40));
  monster_hit_box.setPosition(sf::Vector2f(getSprite()->getPosition().x - 25,
                                           getSprite()->getPosition().y + 20));

}



//Getters && Setters
const sf::RectangleShape& Monster::getMonsterHitBox() const
{
  return monster_hit_box;
}
Entities::MovementStates Monster::getMoveState() const
{
  return move_state;
}
void Monster::setMoveState(Entities::MovementStates moveState)
{
  move_state = moveState;
}