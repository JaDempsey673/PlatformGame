//
// Created by TheRe on 12/04/2023.
//

#ifndef PLATFORMERSFML_KEYS_H
#define PLATFORMERSFML_KEYS_H

#include "SFML/Graphics.hpp"


class Keys
{
 public:
  void keysInit(int i);
  bool collection(sf::RectangleShape hit_box);

 private:
  sf::Texture key_texture;
  sf::Sprite key_sprite;
  bool active = true;



  //Getters && Setters
 public:
  const sf::Sprite& getKeySprite() const;
  bool isActive() const;
  void setActive(bool active);

};

#endif // PLATFORMERSFML_KEYS_H
