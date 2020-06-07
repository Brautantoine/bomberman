#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "elements/elements.hpp"
#include "graphics/sprite.hpp"


class block : virtual sprite, public elements
{

public:
  block(){};
  block(std::string img_name,int x, int y, e_type type);
  virtual ~block();
  void vanish();
  void draw(sf::RenderWindow& w);
  int getLayer(){return 1;}
  e_type get_type() {return _type;}
  void self_register();

  bool check_collision(int x, int y);
protected:
private:
  bool visible;

  e_type _type;

  int _x;
  int _y;

  std::string _img_name;

  sf::Texture texture;
  sf::Sprite sprite;
};


#endif //BLOCK_HPP
