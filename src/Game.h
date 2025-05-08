
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Monster.h"
#include "Player.h"
#include "Map.h"
#include "Keys.h"
#include "Exit.h"


class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void deathCheck();

  void menuInit();
  void winScreen();
  void lossScreen();
  void endGameOptions();
  void gameBackgroundInit();
  void cameraInit();
  void livesInit();
  void keysInit();
  void audioInit();
  void audioController();
  void Reset();
  void jumpScareInit();
  void jumpScare();

 private:
  sf::RenderWindow& window;

  enum class GameState
  {
    MENU = 0,
    DEATH = 1,
    WIN = 2,
    LEVEL = 3,
    JUMP_SCARE = 4,
  };
  GameState Active {GameState::MENU};

  Player player;

  Monster monster1;
  Monster monster2;
  Monster monster3;
  Monster monster4;
  Monster monster5;
  Monster monster6;
  Monster monster7;
  Monster monster8;

  Monster monsters[8] = {monster1,monster2,
                          monster3,monster4,
                          monster5,monster6,
                          monster7,monster8};
  Map map1;
  Exit exit1;

  Keys key1;
  Keys key2;
  Keys key3;

  Keys keys[3] = {key1, key2, key3};

  int keys_collected = 0;
  int lives = 3;
  bool other = false;
  bool reset = false;
  bool second_jump;
  sf::Clock buffer;
  sf::Clock jumpscare;

  sf::Text menu_text;
  sf::Text controls;
  sf::Text win_text;
  sf::Text loss_text;
  sf::Text reset_option;
  sf::Text quit_option;
  sf::Text lives_max;
  sf::Text current_life;
  sf::Text keys_max;
  sf::Text current_keys;
  sf::Font open_sans;

  sf::SoundBuffer menu;
  sf::Sound menu_song;

  sf::SoundBuffer level_one;
  sf::Sound level_one_song;

  sf::SoundBuffer jumpscare_buffer;
  sf::Sound jumpscare_sound;

  sf::Texture background_0;
  sf::Sprite bg_sprite_0;

  sf::Texture background_1;
  sf::Sprite bg_sprite_1;

  sf::Texture background_2;
  sf::Sprite bg_sprite_2;

  sf::Texture jump_scare_text;
  sf::Sprite jump_scare_sprite;

  sf::View FollowCamera;
  sf::View StaticCamera;
};

#endif // PLATFORMER_GAME_H
