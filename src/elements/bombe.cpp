#include "elements/bombe.hpp"

bombe::bombe()
{
  //std::cerr << "constr called" << '\n';
  texture.loadFromFile("ressources/img/bomb.png");
  sprite.setTexture(texture);
  //sprite.setPosition(x,y);
  //layout_manager::getInstance()->registerDrawable(this);

  active = false;
}

bombe::~bombe()
{
  if(active)
    layout_manager::getInstance()->unregisterDrawable(this);
}


void bombe::draw(sf::RenderWindow& w)
{
  //std::cerr << "draw called for bombe" << '\n';
  w.draw(sprite);
}

void bombe::spawn(int x, int y)
{
  if(!active)
  {
    std::cerr << "register bomb in " << x <<":"<<y << '\n';
    sprite.setPosition(x,y);
    layout_manager::getInstance()->registerDrawable(this);
    active = true;
  }


}
