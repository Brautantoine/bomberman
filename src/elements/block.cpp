#include "elements/block.hpp"

block::block(std::string img_name,int x, int y, e_type type) : _img_name(img_name), _x(x), _y(y), _type(type)
{
  texture.loadFromFile(_img_name);
  sprite.setTexture(texture);
  sprite.setPosition(x,y);
  layout_manager::getInstance()->registerDrawable(this);

  visible = true;
}

block::~block()
{
  if(visible)
    layout_manager::getInstance()->unregisterDrawable(this);
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
  w.draw(sprite);
}
