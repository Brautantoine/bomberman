#include "elements/bomberman.hpp"

bomberman::bomberman(int id) :_id(id)
{
  switch(id)
  {
    case 0:
      texture.loadFromFile("ressources/img/b1.png");
      sprite.setTexture(texture);
      sprite.setPosition(SPRITE_H*0,SPRITE_W*1);
      break;
    case 1:
      texture.loadFromFile("ressources/img/b2.png");
      sprite.setTexture(texture);
      sprite.setPosition(SPRITE_H*9,SPRITE_W*9);
      break;


  }
  layout_manager::getInstance()->registerDrawable(this);
}

bomberman::~bomberman()
{
  layout_manager::getInstance()->unregisterDrawable(this);
}

void bomberman::update()
{
  //engine* e = engine::getInstance();

  switch(_id)
  {
    case 0:
    //std::cerr << "b left" << '\n';

    switch(engine::getInstance()->get_input().arrow)
    {
      case LEFT:
      sprite.move(-10,0);
        break;
      case RIGHT:
      sprite.move(10,0);
        break;
      case UP:
      sprite.move(0,-10);
        break;
      case DOWN:
      sprite.move(0,10);
        break;
      case STOP:
        break;
    }
    break;
    case 1:
    switch(engine::getInstance()->get_input().zqsd)
    {
      case LEFT:
      sprite.move(-10,0);
        break;
      case RIGHT:
      sprite.move(10,0);
        break;
      case UP:
      sprite.move(0,-10);
        break;
      case DOWN:
      sprite.move(0,10);
        break;
      case STOP:
        break;
    }
    break;


    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      std::cerr << "b left" << '\n';
      sprite.move(-10,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      sprite.move(10,0);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      sprite.move(0,-10);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      sprite.move(0,10);
    }*/
  }
}

void bomberman::draw(sf::RenderWindow& w)
{
  //std::cerr << "drawn" << '\n';
  w.draw(sprite);
}
