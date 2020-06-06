#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "elements/elements.hpp"
#include "graphics/sprite.hpp"

#include <vector>

class bombe : public sprite, public elements
{
public:
  bombe();
  virtual ~bombe();
  void draw(sf::RenderWindow& w);
  int getLayer(){return 3;}

  void spawn(int x, int y);
  bool check_collision(int x, int y){return true;}
private:

  bool active;

  sf::Texture texture;
  sf::Sprite sprite;

};

#endif //BOMBE_HPP
