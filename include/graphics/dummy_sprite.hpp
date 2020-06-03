#ifndef DUMMY_SPRITE_HPP
#define DUMMY_SPRITE_HPP

#include "graphics/drawable.hpp"
#include <iostream>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class dummy_sprite: public drawable {

public:
  void draw(sf::RenderWindow& w) override;
  dummy_sprite(int _layer);
  int getLayer() {return layer;}
protected:
private:
  sf::Texture texture;
  sf::Sprite sprite;

  int layer;

};

#endif //DUMMY_SPRITE_HPP
