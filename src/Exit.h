//
// Created by TheRe on 12/04/2023.
//

#ifndef PLATFORMERSFML_EXIT_H
#define PLATFORMERSFML_EXIT_H

#include "SFML/Graphics.hpp"

class Exit
{
 public:
  void exitInit();

 private:
  sf::Texture exit_texture;
  sf::Sprite exit_sprite;



  //Getters && Setters
 public:
  const sf::Sprite& getExitSprite() const;
};

#endif // PLATFORMERSFML_EXIT_H
