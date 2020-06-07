#ifndef BOMBE_HPP
#define BOMBE_HPP

#include "elements/elements.hpp"
#include "elements/bomberman.hpp"
#include "graphics/sprite.hpp"

#include <vector>

class bombe : public sprite, public elements
{
public:
  bombe();
  virtual ~bombe();
  void draw(sf::RenderWindow& w);
  int getLayer(){return 2;}
  e_type get_type() {return etype;}

  void spawn(int x, int y);
  bool check_collision(int x, int y){return true;}

  bool update(std::vector<bomberman*>& bmans, std::vector<elements*>& blocks, std::vector<elements*>& affected);
  void vanish();
private:

  bool active;

  sf::Texture texture;
  sf::Texture etexture;
  sf::Sprite sprite;
  std::vector<sf::Sprite> esprites;

  int update_count;
  int frame_count;
  int range;
  int center_x;
  int center_y;

  bool l_stop;
  bool r_stop;
  bool u_stop;
  bool d_stop;

  void find_affected(std::vector<bomberman*>& bmans, std::vector<elements*>& blocks, std::vector<elements*>& affected,int index);

};

#endif //BOMBE_HPP
