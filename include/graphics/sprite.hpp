#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <string>
#include "graphics/drawable.hpp"
#include"graphics/layout_manager.hpp"

#define SPRITE_W 48
#define SPRITE_H 64

class sprite : public drawable
{
public:
  //virtual sprite(std::string img_name,int x, int y);
  virtual void draw(sf::RenderWindow& w)=0;
  virtual int getLayer()=0;
protected:
  int _x;
  int _y;
  std::string name;
};

#endif //SPRITE_HPP
