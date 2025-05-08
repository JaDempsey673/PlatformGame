#include "Game.h"
#include "Entities.h"

#include <iostream>
#include <SFML/Graphics.hpp>


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  menuInit();
  winScreen();
  lossScreen();
  endGameOptions();
  map1.mapInit();
  player.playerInit();
  exit1.exitInit();
  livesInit();
  keysInit();
  jumpScareInit();
  audioInit();

  for(int i = 0; i < 8; i++)
  {
    monsters[i].monsterMap1Init(i);
  }

  gameBackgroundInit();
  cameraInit();
  
  return true;
}

void Game::menuInit()
{
  if (!open_sans.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Failed to load font: OpenSans line 27";
  }

  menu_text.setString("Platformed");
  menu_text.setFillColor(sf::Color(144, 100, 100, 128));
  menu_text.setFont(open_sans);
  menu_text.setCharacterSize(100);
  menu_text.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 5 - menu_text.getGlobalBounds().height);

  controls.setString(" W,A,S,D to Move \n Space to Jump \n Left click to attack \n Collect keys to win");
  controls.setFillColor(sf::Color(144, 100, 100, 128));
  controls.setFont(open_sans);
  controls.setCharacterSize(40);
  controls.setPosition(
    window.getSize().x / 2 - controls.getGlobalBounds().width / 2,
    window.getSize().y / 2 - controls.getGlobalBounds().height + 100);

}

void Game::winScreen()
{
  win_text.setString("Congrats! You Win");
  win_text.setFillColor(sf::Color(144,100,100,128));
  win_text.setFont(open_sans);
  win_text.setCharacterSize(100);
  win_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2 - 160,
                        window.getSize().y / 6 - menu_text.getGlobalBounds().height);

}

void Game::lossScreen()
{
  loss_text.setString("You Have Died");
  loss_text.setFillColor(sf::Color(144,100,100,128));
  loss_text.setFont(open_sans);
  loss_text.setCharacterSize(100);
  loss_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2 - 60,
                        window.getSize().y / 6 - menu_text.getGlobalBounds().height);
}

void Game::endGameOptions()
{
  reset_option.setString("> Replay");
  reset_option.setFillColor(sf::Color(144,100,100,128));
  reset_option.setFont(open_sans);
  reset_option.setCharacterSize(50);
  reset_option.setPosition(window.getSize().x / 2 - reset_option.getGlobalBounds().width / 2,
                           window.getSize().y / 4 - reset_option.getGlobalBounds().height + 100);

  quit_option.setString("Quit");
  quit_option.setFillColor(sf::Color(144,100,100,128));
  quit_option.setFont(open_sans);
  quit_option.setCharacterSize(50);
  quit_option.setPosition(window.getSize().x / 2 - quit_option.getGlobalBounds().width / 2,
                        window.getSize().y / 2 - quit_option.getGlobalBounds().height);
}

void Game::gameBackgroundInit()
{
  if (!background_0.loadFromFile("Data/Images/Map/background_0.png"))
  {
    std::cout << "Failed to load font: background 0 line 45";
  }
  bg_sprite_0.setTexture(background_0);
  bg_sprite_0.setScale(3.75,4);

  background_0.setRepeated(true);
  bg_sprite_0.setTextureRect(sf::IntRect(0,0,1000,720));

  if (!background_1.loadFromFile("Data/Images/Map/background_1.png"))
  {
    std::cout << "Failed to load font: background 1";
  }
  bg_sprite_1.setTexture(background_1);
  bg_sprite_1.setScale(3.75,4);

  background_1.setRepeated(true);
  bg_sprite_1.setTextureRect(sf::IntRect(0,0,1000,720));


  if (!background_2.loadFromFile("Data/Images/Map/background_2.png"))
  {
    std::cout << "Failed to load font: background 2";
  }

  bg_sprite_2.setTexture(background_2);
  bg_sprite_2.setScale(3.75,4);

  background_2.setRepeated(true);
  bg_sprite_2.setTextureRect(sf::IntRect(0,0,1000,720));
}

void Game::cameraInit()
{
  FollowCamera.setSize(window.getSize().x, window.getSize().y);
  FollowCamera.setCenter(player.getSprite()->getPosition().x + 300,
                         player.getSprite()->getPosition().y - 120);

  StaticCamera.setSize(window.getSize().x, window.getSize().y);
  StaticCamera.setCenter(player.getSprite()->getPosition().x + 300,
                         player.getSprite()->getPosition().y - 120);
}

void Game::livesInit()
{
  lives = 3;

  current_life.setString(std::to_string(lives));
  current_life.setFillColor(sf::Color(0,0,0,128));
  current_life.setFont(open_sans);
  current_life.setCharacterSize(50);
  current_life.setPosition(window.getSize().x / 5.1 - current_life.getGlobalBounds().width,
                        window.getSize().y / 13.2 - current_life.getGlobalBounds().height);

  lives_max.setString("Lives:   /3");
  lives_max.setFillColor(sf::Color(0,0,0,128));
  lives_max.setFont(open_sans);
  lives_max.setCharacterSize(50);
  lives_max.setPosition(window.getSize().x / 4.1 - lives_max.getGlobalBounds().width,
                       window.getSize().y / 13 - lives_max.getGlobalBounds().height);

}

void Game::keysInit()
{
  for(int i = 0; i < 3; i++)
  {
    keys[i].keysInit(i);
  }

  keys_collected = 0;

  current_keys.setString(std::to_string(keys_collected));
  current_keys.setFillColor(sf::Color(0,0,0,128));
  current_keys.setFont(open_sans);
  current_keys.setCharacterSize(50);
  current_keys.setPosition(window.getSize().x / 1.05 - current_keys.getGlobalBounds().width,
                           window.getSize().y / 13.2 - current_keys.getGlobalBounds().height);

  keys_max.setString("Keys:   /3");
  keys_max.setFillColor(sf::Color(0,0,0,128));
  keys_max.setFont(open_sans);
  keys_max.setCharacterSize(50);
  keys_max.setPosition(window.getSize().x / 1 - keys_max.getGlobalBounds().width,
                        window.getSize().y / 11.3 - keys_max.getGlobalBounds().height);
}

void Game::jumpScareInit()
{
  if (!jump_scare_text.loadFromFile(R"(Data\Images\Enemy\jumpscare.png)"))
  {
    std::cout << "Failed to load jumpscare";
  }
  jump_scare_sprite.setTexture(jump_scare_text);
  jump_scare_sprite.setScale(2,2);
  jump_scare_sprite.setPosition(window.getSize().x / 2 - jump_scare_sprite.getGlobalBounds().width + 350,
                                window.getSize().y / 2 - jump_scare_sprite.getGlobalBounds().height + 350);
}

void Game::jumpScare()
{
  if(!reset)
  {
    jumpscare_sound.play();
    jumpscare.restart();
    reset = true;
  }

  if(jumpscare.getElapsedTime().asSeconds() >= 1)
  {
    Active = GameState::DEATH;
    jumpscare_sound.stop();
    window.close();
  }
}

void Game::audioInit()
{
  if (!menu.loadFromFile(
        R"(Data\Music\menu song.wav)"))
  {
    std::cout << "Sound broken - menu";
  }
  menu_song.setBuffer(menu);

  if (!level_one.loadFromFile(R"(Data\Music\level song.wav)"))
  {
    std::cout << "Sound broken - level one";
  }
  level_one_song.setBuffer(level_one);

  if (!jumpscare_buffer.loadFromFile(R"(Data\Music\jump scare.wav)"))
  {
    std::cout << "Sound broken - jumpscare";
  }

  jumpscare_sound.setBuffer(jumpscare_buffer);
};

void Game::audioController()
{
  switch (Active)
  {
    case GameState::MENU:
      if(!menu_song.getStatus())
      {
        menu_song.play();
      }
      level_one_song.pause();
      break;

    case GameState::LEVEL:
      menu_song.pause();

      if (!level_one_song.getStatus())
        {
          level_one_song.play();
        }
      break;

    case GameState::WIN:
      if(!menu_song.getStatus())
      {
        menu_song.play();
      }

      level_one_song.pause();
      break;

    case GameState::DEATH:
      menu_song.pause();
      level_one_song.pause();
      break;

    case GameState::JUMP_SCARE:
      menu_song.pause();
      level_one_song.pause();
      break;

  }
};

void Game::update(float dt)
{
  if (player.isAttacking() == 1)
  {
    player.setMoveState(Entities::MovementStates::ATTACKING_ONE);
    player.attackHitBox();
  }

  if (player.isDead())
  {
    Active = GameState::DEATH;
  }

  if(player.getSprite()->getPosition().y > 720)
  {
    player.getSprite()->setPosition(250, 400);
    if(!other)
    {
      player.setDead(true);
    }
    else if(other)
    {
      FollowCamera.setCenter(player.getSprite()->getPosition().x + 300,
                             player.getSprite()->getPosition().y - 40);
      jumpScareInit();
    }
  }

  if(player.getSprite()->getPosition().x <= 36 && player.getVelocity().x < 0)
  {
    player.setVelocity(Vector2(0, player.getVelocity().y));
  }

  player.getSprite()->move(
    player.getVelocity().x * dt, player.getVelocity().y * dt);

  player.setVelocity(Vector2(
    player.getVelocity().x, player.getVelocity().y + player.getGravity()));

  audioController();

  if (player.getSprite()->getPosition().x > 250 && player.getSprite()->getPosition().x < 5544 && !player.isDead())
  {
    FollowCamera.move(player.getVelocity().x * dt, 0);
    lives_max.move(player.getVelocity().x * dt, 0);
    current_life.move(player.getVelocity().x * dt, 0);
    keys_max.move(player.getVelocity().x * dt, 0);
    current_keys.move(player.getVelocity().x * dt, 0);
    win_text.move(player.getVelocity().x * dt, 0);
    loss_text.move(player.getVelocity().x * dt, 0);
    reset_option.move(player.getVelocity().x * dt, 0);
    quit_option.move(player.getVelocity().x * dt, 0);
    jump_scare_sprite.move(player.getVelocity().x * dt, 0);

    bg_sprite_0.move(player.getVelocity().x * dt * 0.9,0);
    bg_sprite_1.move(player.getVelocity().x * dt * 0.6,0);
    bg_sprite_2.move(player.getVelocity().x * dt * 0.3,0);
  }

  player.groundCheck();

  if(map1.collisions(player.getGroundCheck(), player.getVelocity()))
  {
    if (!player.isJumped())
    {
      if(player.getVelocity().y >0)
      {
        second_jump = false;
      }
      player.setVelocity(Vector2(player.getVelocity().x, 0));
    }
    else if (player.isJumped() && player.getVelocity().y > 0)
    {
      player.setJumped(false);
      if (player.isMoving())
      {
        player.setVelocity(Vector2(player.getVelocity().x, 0));
      }
      else
      {
        player.setVelocity(Vector2(0, 0));
      }
    }
  }

  if(!player.isAttacking() && !player.isJumped())
  {
    if (player.getVelocity().x == 0)
    {
      player.setMoveState(Entities::MovementStates::IDLE);
    }
    else if (player.getVelocity().x >= 0)
    {
      player.setMoveState(Entities::MovementStates::MOVE_RIGHT);
    }
    else if (player.getVelocity().x <= 0)
    {
      player.setMoveState(Entities::MovementStates::MOVE_LEFT);
    }
  }

  for(auto & monster : monsters)
  {
    monster.updateMonsterAnimation(player.getSprite()->getPosition().x);
  }

  player.updatePlayerAnimations();
  deathCheck();

  for(auto & key : keys)
  {
    if(key.collection(player.getPlayerHitBox()))
    {
      keys_collected++;
    }
  }

  if(player.getPlayerHitBox().getGlobalBounds().intersects(exit1.getExitSprite().getGlobalBounds()))
  {
    if (other)
    {
      Active = GameState::JUMP_SCARE;
      jumpScare();
    }
    if(keys_collected == 3)
    {
      Active = GameState::WIN;
    }
  }

  current_life.setString(std::to_string(lives));
  current_keys.setString(std::to_string(keys_collected));
}

void Game::deathCheck()
{
  player.playerHitBox();
  for (int i = 0; i < 8; i++)
  {
    monsters[i].monsterHitBox();

    if (monsters[i].getMoveState() != Entities::MovementStates::DYING)
    {
      if (player.getPlayerHitBox().getGlobalBounds().intersects(monsters[i].getMonsterHitBox().getGlobalBounds()))
      {
        if (buffer.getElapsedTime().asSeconds() >= 0.5)
        {
          lives -= 1;
          buffer.restart();
        }

        if (lives <= 0)
        {
          player.setMoveState(Entities::MovementStates::DYING);
          player.setVelocity(Vector2(0, player.getVelocity().y));
        }
      }

      if (player.isAttacking())
      {
        if (player.getAttackOneHitBox().getGlobalBounds().intersects(
              monsters[i].getMonsterHitBox().getGlobalBounds()))
        {
          monsters[i].setMoveState(Entities::MovementStates::DYING);
        }
      }
    }
  }
}

void Game::render()
{
  switch(Active)
  {
    case GameState::MENU:
      window.draw(menu_text);
      window.draw(controls);
      break;

    case GameState::DEATH:
      window.draw(loss_text);
      window.draw(reset_option);
      window.draw(quit_option);
      break;

    case GameState::WIN:
      window.draw(win_text);
      window.draw(reset_option);
      window.draw(quit_option);
      break;

    case GameState::LEVEL:
      window.setView(FollowCamera);

      window.draw(bg_sprite_0);
      window.draw(bg_sprite_1);
      window.draw(bg_sprite_2);
      window.draw(exit1.getExitSprite());
      window.draw(map1.getMap1Sprite());
      window.draw(lives_max);
      window.draw(current_life);
      window.draw(keys_max);
      window.draw(current_keys);

      for(int i = 0; i < 3; i++)
      {
        if(keys[i].isActive())
        {
          window.draw(keys[i].getKeySprite());
        }
      }


      for(int i = 0; i < 8; i++)
      {
        window.draw(*monsters[i].getSprite());
      }

      window.draw(*player.getSprite());
      break;

    case GameState::JUMP_SCARE:
      window.draw(jump_scare_sprite);
      break;

    default:
      std::cout << "GameState Switch Error: Line 43";
      break;
  }
}

void Game::mouseClicked(sf::Event event)
{
  if (Active == GameState::MENU)
  {
    Active = GameState::LEVEL;
    player.setAttacking(0);
  }
  if (Active == GameState::LEVEL)
  {
    if(player.getMoveState() != Entities::MovementStates::DYING)
    {
      player.setAttacking(1);
      player.setCurrentFrameLeft(0);
    }
  }
}

void Game::keyPressed(sf::Event event)
{
  if (player.getMoveState() != Entities::MovementStates::DYING && Active == GameState::LEVEL)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
      player.setMoving(true);
      player.setVelocity(Vector2(-300, player.getVelocity().y));

      if (player.getSprite()->getScale().x == 3.f)
      {
        player.getSprite()->setScale(-3.f, 3.f);
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      player.setMoving(true);
      player.setVelocity(Vector2(300, player.getVelocity().y));

      if (player.getSprite()->getScale().x == -3.f)
      {
        player.getSprite()->setScale(3.f, 3.f);
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
      if(player.isJumped())
      {
        if(!second_jump)
        {
          second_jump = true;
          player.setVelocity(
            Vector2(player.getVelocity().x, player.getHeight()));
        }
      }
      else
      {
        player.setMoveState(Player::MovementStates::JUMPING);
        player.setJumped(true);
        player.setVelocity(Vector2(player.getVelocity().x, player.getHeight()));
      }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      window.close();
    }
  }
  if(Active == GameState::DEATH || Active == GameState::WIN)
  {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      reset_option.setString("> Replay");
      quit_option.setString("Quit");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      reset_option.setString("Replay");
      quit_option.setString("> Quit");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
      if (quit_option.getString() == "> Quit")
      {
        window.close();
      }
      else if (reset_option.getString() == "> Replay")
      {
       Reset();
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      window.close();
    }
  }
}

void Game::keyReleased(sf::Event event)
{
  if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A))  && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
  {
    player.setMoving(false);
  }

  if(!player.isJumped())
  {
    player.setMoveState(Player::MovementStates::IDLE);
    player.setVelocity(Vector2(0, player.getVelocity().y));
  }
}

void Game::Reset()
{
  player.getSprite()->setPosition(250, 350);
  keys_collected = 0;
  lives = 3;
  other = false;
  reset = false;
  player.setDead(false);
  second_jump = false;

  if (Active == GameState::WIN)
  {
    menu_song.stop();
    init();
    other = true;
    for (auto& monster : monsters)
    {
      monster.setMoveState(Entities::MovementStates::DYING);
    }
    level_one_song.setPitch(0.5);
    level_one_song.play();
    window.setTitle("P̵̟̭̜̰̲̯̝̔̈́ͅl̵̡͙̰̩̩̬̈́̂̄͆͝ȧ̴̞͖̹̭͓̦̱̎́t̸̪̹̩̘͎͇͓̝̊̅͗́̕͠f̵̮̟̌̓͌͘͠ö̷͔̭͎̲̱̘͕̪́͑̆͐̎͑͝ŕ̴͓͈͉̠̗͒ͅm̵̨͚͖̆̈́̒̓́͋ ̶̡̪͇̝̟̳̲̈́̎̀͆̕͘͜͝G̶̬̦̯̱̭̀̈̑̅̀a̷͖̬͔̭̟̒̇͂͌m̸̨̨̠̗̓̀̅̑̃ê̴̞̼̦̇͆̽");
  }
  else if (Active == GameState::DEATH)
  {
    bg_sprite_0.setPosition(0,0);
    bg_sprite_1.setPosition(0,0);
    bg_sprite_2.setPosition(0,0);
    init();
    other = false;
    keys_collected = 0;

    for(int i = 0; i< 3; i++)
      {
        keys[i].setActive(true);
      }
  }

  Active = GameState::LEVEL;
}