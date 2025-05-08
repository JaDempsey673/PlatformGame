
#include "Keys.h"
#include <iostream>

void Keys::keysInit(int i)
{
  if (!key_texture.loadFromFile(R"(Data\Images\Map\Key.png)"))
  {
    std::cout << "Failed to load font: background 0 line 45";
  }
  key_sprite.setTexture(key_texture);
  key_sprite.setScale(0.1,0.1);

  switch(i)
  {
    case 0:
      key_sprite.setPosition(1419, 579);
      break;

    case 1:
      key_sprite.setPosition(3010, 226);
      break;

    case 2:
      key_sprite.setPosition(5714, 50);
      break;

    default:
      break;
  }
}

bool Keys::collection(sf::RectangleShape hit_box)
{
  if(active && hit_box.getGlobalBounds().intersects(key_sprite.getGlobalBounds()))
  {
    active = false;
  }
}

//Getters && Setters
const sf::Sprite& Keys::getKeySprite() const
{
  return key_sprite;
}
bool Keys::isActive() const
{
  return active;
}
void Keys::setActive(bool active)
{
  Keys::active = active;
}
