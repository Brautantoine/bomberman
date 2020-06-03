#include "graphics/dummy_sprite.hpp"

dummy_sprite::dummy_sprite(int _layer)
{
  texture.loadFromFile("ressources/img/rowlet.png");
  sprite.setTexture(texture);
  layer = _layer;
}

void dummy_sprite::draw(sf::RenderWindow& w)
{
  w.draw(sprite);
}
