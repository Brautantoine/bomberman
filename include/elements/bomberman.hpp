#ifndef BOMBERMAN_HPP
#define BOMBERMAN_HPP

#include "events/event_processor.hpp"
#include "utils/simple_mail_box.hpp"
#include "elements/elements.hpp"
#include "graphics/sprite.hpp"
#include "graphics/layout_manager.hpp"
#include "graphics/engine.hpp"

#include <SFML/Window/Event.hpp>


class bomberman : virtual elements, virtual sprite
{
public:
  bomberman(int id);
  virtual ~bomberman();
  void update();
  void draw(sf::RenderWindow& w);
  int getLayer(){return 1;}
protected:
private:

  //simple_mail_box<sf::Event> mail_box;
  //event_processor ep;

  //btype _type;
  int _id;

  sf::Texture texture;
  sf::Sprite sprite;
};

#endif //BOMBERMAN_HPP
