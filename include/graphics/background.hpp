#ifndef BACKGROUND_HPP
#define BACKGROUND_HPP

#include <string>
#include "graphics/drawable.hpp"
#include "graphics/layout_manager.hpp"

class background : virtual drawable
{
public:
  background(std::string img_name);
  ~background();
  void draw(sf::RenderWindow& w);
  int getLayer();
protected:
  std::string name;

  sf::Texture texture;
  sf::Sprite sprite;
};

#endif //BACKGROUND_HPP
