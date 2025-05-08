//
// Created by TheRe on 08/04/2023.
//

#ifndef PLATFORMERSFML_MAP_H
#define PLATFORMERSFML_MAP_H

#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Monster.h"

class Map
{
 public:
  void mapInit();
  bool collisions(const sf::RectangleShape& hit_box, Vector2 velocity);

 private:
  sf::Texture map1_texture;
  sf::Sprite map1_sprite;

  sf::RectangleShape hit_blocks_1;
  sf::RectangleShape hit_blocks_2;
  sf::RectangleShape hit_blocks_3;
  sf::RectangleShape hit_blocks_4;
  sf::RectangleShape hit_blocks_5;
  sf::RectangleShape hit_blocks_6;
  sf::RectangleShape hit_blocks_7;
  sf::RectangleShape hit_blocks_8;
  sf::RectangleShape hit_blocks_9;
  sf::RectangleShape hit_blocks_10;
  sf::RectangleShape hit_blocks_11;
  sf::RectangleShape hit_blocks_12;

  std::vector<sf::RectangleShape> hit_blocks_bundle;




  //Getters && Setters
 public:
  const sf::Sprite& getMap1Sprite() const;
};

#endif // PLATFORMERSFML_MAP_H
