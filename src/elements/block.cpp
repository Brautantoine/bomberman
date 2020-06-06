#include "elements/block.hpp"

block::block(std::string img_name,int x, int y, e_type type) : _img_name(img_name), _x(x), _y(y), _type(type)
{
  std::cerr << "register block for " << _x << ":" << _y << " with " << this << '\n';
  texture.loadFromFile(_img_name);
  sprite.setTexture(texture);
  sprite.setPosition(x,y);
  layout_manager::getInstance()->registerDrawable(this);

  visible = true;
}

block::~block()
{
  std::cerr << "called destructor for" << this << '\n';
  if(visible)
  {
    layout_manager::getInstance()->unregisterDrawable(this);
    visible = false;
  }
}

void block::self_register()
{
  /*layout_manager::getInstance()->registerDrawable(this);
  visible = true;*/
}

void block::vanish()
{
  if(visible)
  {
    layout_manager::getInstance()->unregisterDrawable(this);
    visible = false;
  }
}

void block::draw(sf::RenderWindow& w)
{
  //std::cerr << "draw called for " << _x << ":" << _y << '\n';
  w.draw(sprite);
}

bool block::check_collision(int x, int y)
{
  std::cerr << "with " << _x << ":" << _y << '\n';
  std::cerr << "l :" << x << ":" << _x << ":" << (x < _x) << '\n';
  std::cerr << "r :" << x << ":" << _x+SPRITE_W << ":" << (x > _x+SPRITE_W) << '\n';
  std::cerr << "u :" << y << ":" << _y << ":" << (y < _y) << '\n';
  std::cerr << "d :" << y << ":" << _y+SPRITE_H << ":" << (y > _y+SPRITE_H) << '\n';
  std::cerr << "result : " << (x <= _x ||
          x >= _x + SPRITE_W ||
          y <= _y ||
          y >= _y + SPRITE_H
        ) << '\n';
  return (x <= _x ||
          x >= _x + SPRITE_W ||
          y <= _y ||
          y >= _y + SPRITE_H
        );
}
