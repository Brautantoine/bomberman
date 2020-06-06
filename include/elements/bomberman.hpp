#ifndef BOMBERMAN_HPP
#define BOMBERMAN_HPP

#include "events/event_processor.hpp"
#include "utils/simple_mail_box.hpp"
#include "elements/elements.hpp"
#include "graphics/sprite.hpp"
#include "graphics/layout_manager.hpp"
#include "graphics/engine.hpp"

#include <SFML/Window/Event.hpp>

struct position
{
  int x;
  int y;

  position(int _x, int _y)
  {
    x = _x;
    y = _y;
  }
};

class bomberman : public elements, public sprite
{
public:
  bomberman(int id);
  virtual ~bomberman();
  virtual void update(std::vector<elements*> e);
  void draw(sf::RenderWindow& w);
  int getLayer(){return 3;}
  bool check_outbound(direction dir);
  bool check_collision(int x, int y);
  position get_position() { return position(_x,_y);}
protected:
  int _id;
  int speed;

  sf::Texture texture;
  sf::Sprite sprite;
private:

  //simple_mail_box<sf::Event> mail_box;
  //event_processor ep;

  //btype _type;

};

#endif //BOMBERMAN_HPP
