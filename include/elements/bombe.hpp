#ifndef BOMBE_HPP
#define BOMBE_HPP

class bombe : public sprite, public elements
{
public:
  bombe();
  virtual ~bombe();
  void draw(sf::RenderWindow& w);
  int getLayer(){return 2;}

  void spawn();
private:

  bool active;

  sf::Texture texture;
  sf::Sprite sprite;

}

#endif //BOMBE_HPP
