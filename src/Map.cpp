
#include "Map.h"
#include <iostream>

void Map::mapInit()
{
  if (!map1_texture.loadFromFile(R"(Data\Images\Map\Map1.png)"))
  {
    std::cout << "Failed to load font: background 0 line 45";
  }
  map1_sprite.setTexture(map1_texture);

  hit_blocks_1.setPosition(0,592);
  hit_blocks_1.setSize(sf::Vector2f(480,32));

  hit_blocks_2.setPosition(668,464);
  hit_blocks_2.setSize(sf::Vector2f(320,32));;

  hit_blocks_3.setPosition(1216,368);
  hit_blocks_3.setSize(sf::Vector2f(272,32));

  hit_blocks_4.setPosition(1600,560);
  hit_blocks_4.setSize(sf::Vector2f(320,32));

  hit_blocks_5.setPosition(2080,432);
  hit_blocks_5.setSize(sf::Vector2f(320,32));

  hit_blocks_6.setPosition(2560,304);
  hit_blocks_6.setSize(sf::Vector2f(640,32));

  hit_blocks_7.setPosition(3280,480);
  hit_blocks_7.setSize(sf::Vector2f(432,32));

  hit_blocks_8.setPosition(4176,496);
  hit_blocks_8.setSize(sf::Vector2f(416,32));

  hit_blocks_9.setPosition(4640,368);
  hit_blocks_9.setSize(sf::Vector2f(368,32));

  hit_blocks_10.setPosition(5088,240);
  hit_blocks_10.setSize(sf::Vector2f(320,32));

  hit_blocks_11.setPosition(5504,128);
  hit_blocks_11.setSize(sf::Vector2f(304,32));

  hit_blocks_12.setPosition(6080,400);
  hit_blocks_12.setSize(sf::Vector2f(320,32));

  hit_blocks_bundle =
    {
      hit_blocks_1, hit_blocks_2, hit_blocks_3, hit_blocks_4, hit_blocks_5, hit_blocks_6,
      hit_blocks_7, hit_blocks_8, hit_blocks_9, hit_blocks_10 , hit_blocks_11, hit_blocks_12,
    };
}

bool Map::collisions(const sf::RectangleShape& hit_box, Vector2 velocity)
{
  for (auto& i : hit_blocks_bundle)
  {
    if(hit_box.getGlobalBounds().intersects(i.getGlobalBounds()))
    {
      return true;
    }
  }
  return false;
}

//Getters && Setters
const sf::Sprite& Map::getMap1Sprite() const
{
  return map1_sprite;
}
