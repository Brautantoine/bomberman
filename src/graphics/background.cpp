#include "graphics/background.hpp"

background::background(std::string img_name) : name(img_name)
{
  texture.loadFromFile(name);
  sprite.setTexture(texture);
  layout_manager::getInstance()->registerDrawable(this);
}

background::~background()
{
  layout_manager::getInstance()->unregisterDrawable(this);
}

void background::draw(sf::RenderWindow& w)
{
  w.draw(sprite);
}

int background::getLayer()
{
  return 0;
}
