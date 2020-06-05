#include "elements/bomberman.hpp"

bomberman::bomberman(int id) :_id(id)
{
  switch(id)
  {
    case 0:
      texture.loadFromFile("ressources/img/b1.png");
      sprite.setTexture(texture);
      sprite.setPosition(SPRITE_H*0,SPRITE_W*1);
      _x = SPRITE_H*0;
      _y = SPRITE_W*1;
      break;
    case 1:
      texture.loadFromFile("ressources/img/b2.png");
      sprite.setTexture(texture);
      sprite.setPosition(SPRITE_H*9,SPRITE_W*9);
      _y = SPRITE_H*9;
      _x = SPRITE_W*9;
      break;




  }
  speed = 10;
  layout_manager::getInstance()->registerDrawable(this);
}

bomberman::~bomberman()
{
  layout_manager::getInstance()->unregisterDrawable(this);
}

void bomberman::update()
{
  //engine* e = engine::getInstance();
  direction dir = STOP;

  switch(_id)
  {
    case 0:
    dir = engine::getInstance()->get_input().arrow;
    break;
    case 1:
    dir = engine::getInstance()->get_input().zqsd;
    break;
    //std::cerr << "b left" << '\n';
  }
    switch(dir)
    {
      case LEFT:
      if(check_outbound(LEFT))
      {
        sprite.move(-10,0);
        _x-=speed;
      }
      break;
      case RIGHT:
      if(check_outbound(RIGHT))
      {
        sprite.move(10,0);
        _x+=speed;
      }
      break;
      case UP:
      if(check_outbound(UP))
      {
        sprite.move(0,-10);
        _y-=speed;
      }
      break;
      case DOWN:
      if(check_outbound(DOWN))
      {
        sprite.move(0,10);
        _y+=speed;
      }
      break;
      case STOP:
        break;
    }
    /*switch(engine::getInstance()->get_input().zqsd)
    {
      case LEFT:
      if(check_outbound())
        sprite.move(-10,0);
        break;
      case RIGHT:
      if(check_outbound)
        sprite.move(10,0);
        break;
      case UP:
      if(check_outbound)
        sprite.move(0,-10);
        break;
      case DOWN:
      if(check_outbound)
        sprite.move(0,10);
        break;
      case STOP:
        break;
    }*/
}

void bomberman::draw(sf::RenderWindow& w)
{
  //std::cerr << "drawn" << '\n';
  w.draw(sprite);
}

bool bomberman::check_outbound(direction dir)
{
  bool ret = true;
  switch(dir)
  {
    case LEFT:
      if(_x-speed < 0)
        ret = false;
      break;
    case RIGHT:
      if(_x+speed > SCREEN_H-SPRITE_H)
        ret = false;
      break;
    case UP:
    //std::cerr << "y:" << _y << "speed:" << speed << "=" << _y-speed << '\n';
      if(_y-speed < 0)
        ret = false;
      break;
    case DOWN:
      if(_y+speed > SCREEN_W-SPRITE_W)
        ret = false;
      break;
      case STOP:
      break;
  }
  //std::cerr << ret << '\n';
  return ret;
}
