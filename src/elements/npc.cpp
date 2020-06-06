#include "elements/npc.hpp"

void npc::update(std::vector<elements*> e)
{
  direction dir;
  static bool init(false);
  bool validate = true;

  if(!init)
  {
    std::srand(std::time(nullptr));
    init = true;
  }

  switch(std::rand()/((RAND_MAX + 1u)/5))
  {
    case 1:
      dir = LEFT;
      break;
    case 2:
      dir = RIGHT;
      break;
    case 3:
      dir = UP;
      break;
    case 4:
      dir = DOWN;
      break;
    case 5:
      dir = STOP;
      break;
  }
  switch(dir)
  {
    case LEFT:
    for(elements* el : e)
    {
      std::cerr << "checking collisin for" << _x << ":" << _y << ":" << _x << ":" << _y+SPRITE_H << '\n';
      if(!(el->check_collision(_x-speed-10,_y+20) && el->check_collision(_x-speed-10,_y+SPRITE_H-20)))
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
      if(!(el->check_collision(_x+SPRITE_H-10+speed,_y+20) && el->check_collision(_x+SPRITE_H+speed-10,_y+SPRITE_H-20)))
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
      if(!(el->check_collision(_x,_y-speed+20) && el->check_collision(_x+SPRITE_W,_y-speed+20)))
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
      if(!(el->check_collision(_x,_y+SPRITE_H+speed-20) && el->check_collision(_x+SPRITE_W,_y+SPRITE_H+speed-20)))
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
