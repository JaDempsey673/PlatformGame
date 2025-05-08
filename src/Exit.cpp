//
// Created by TheRe on 12/04/2023.
//

#include "Exit.h"
#include <iostream>

void Exit::exitInit()
{
  if (!exit_texture.loadFromFile(R"(Data\Images\Map\Exit.png)"))
  {
    std::cout << "Failed to load font: background 0 line 45";
  }
  exit_sprite.setTexture(exit_texture);
  exit_sprite.setPosition(6250,292);
  exit_sprite.setScale(0.2,0.2);
}


//Getters && Setters
const sf::Sprite& Exit::getExitSprite() const
{
  return exit_sprite;
}