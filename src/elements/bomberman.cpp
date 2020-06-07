#include "elements/bomberman.hpp"

bomberman::bomberman(int id) :_id(id)
{
  switch(id)
  {
    case 0:
      if(!(texture.loadFromFile("ressources/img/b1.png")))
      throw std::runtime_error("can't load b1.png");
      sprite.setTexture(texture);
      sprite.setPosition(SPRITE_H*0,SPRITE_W*0);
      _x = SPRITE_H*0;
      _y = SPRITE_W*0;
      break;
    case 1:
      if(!(texture.loadFromFile("ressources/img/b2.png")))
      throw std::runtime_error("can't load b2.png");
      sprite.setTexture(texture);
      sprite.setPosition(SPRITE_H*9,SPRITE_W*9);
      _x = SPRITE_H*9;
      _y = SPRITE_W*9;
      break;




  }
  speed = 10;
  etype = PC;
  layout_manager::getInstance()->registerDrawable(this);
}

bomberman::~bomberman()
{
  layout_manager::getInstance()->unregisterDrawable(this);
}

void bomberman::update(std::vector<elements*> e)
{

  /**
  *
  * TO ENSURE SMOOTH COLLISION, BOMBERMAN HITBOX ARE SHRINK THAT'S WHY THERE IS SOME SWAP BETWEEN SPRITE_H AND SPRITE_W
  *
  */
  //engine* e = engine::getInstance();
  direction dir = STOP;
  bool validate = true;

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
      for(elements* el : e)
      {
        std::cerr << "checking collisin for" << _x << ":" << _y << ":" << _x << ":" << _y+SPRITE_H << '\n';
        if(!(el->check_collision(_x-speed-10,_y+35) && el->check_collision(_x-speed-10,_y+SPRITE_H-25)))
          validate = false;
      }
      if(check_outbound(LEFT))
      {
        if(validate)
        {
          sprite.move(-10,0);
          _x-=speed;
        }
      }
      else
      {
        sprite.move(-_x,0);
        _x = 0;
      }
      break;
      case RIGHT:
      for(elements* el : e)
      {
        std::cerr << "checking collisin for" << _x << ":" << _y << ":" << _x << ":" << _y+SPRITE_H << '\n';
        if(!(el->check_collision(_x+SPRITE_H-10+speed,_y+35) && el->check_collision(_x+SPRITE_H+speed-10,_y+SPRITE_H-25)))
          validate = false;
      }
      if(check_outbound(RIGHT))
      {
        if(validate)
        {
          sprite.move(10,0);
          _x+=speed;
        }

      }
      else
      {
        sprite.setPosition(SPRITE_H*9,_y);
        _x=SPRITE_H*9;
      }
      break;
      case UP:
      for(elements* el : e)
      {
        std::cerr << "checking collisin for" << _x << ":" << _y << ":" << _x << ":" << _y+SPRITE_H << '\n';
        if(!(el->check_collision(_x+5,_y-speed+20) && el->check_collision(_x+SPRITE_W-5,_y-speed+20)))
          validate = false;
      }
      if(check_outbound(UP))
      {
        if(validate)
        {
          sprite.move(0,-10);
          _y-=speed;
        }

      }
      else
      {
        sprite.move(0,-_y);
        _y = 0;
      }
      break;
      case DOWN:
      for(elements* el : e)
      {
        std::cerr << "type : " << el->get_type() << '\n';
        if(!(el->check_collision(_x+5,_y+SPRITE_H+speed-20) && el->check_collision(_x-5+SPRITE_W,_y+SPRITE_H+speed-20)))
          validate = false;
      }
      if(check_outbound(DOWN))
      {
        if(validate)
        {
          sprite.move(0,10);
          _y+=speed;
        }

      }
      else
      {
        sprite.setPosition(_x,SPRITE_W*9);
        _y=SPRITE_W*9;
      }
      break;
      case STOP:
        break;
    }
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

bool bomberman::check_collision(int x, int y)
{
        return (x <= _x ||
                x >= _x + SPRITE_W ||
                y <= _y ||
                y >= _y + SPRITE_H
              );
}
