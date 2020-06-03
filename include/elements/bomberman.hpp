#ifndef BOMBERMAN_HPP
#define BOMBERMAN_HPP

#include "events/event_processor.hpp"
#include "utils/simple_mail_box.hpp"
#include "elements/elements.hpp"

#include <SFML/Window/Event.hpp>

enum btype
{
  PC,
  NPC,
};

class bomberman : public elements
{
public:
  bomberman(btype type, int id);
  virtual ~bomberman();
protected:
private:

  simple_mail_box<sf::Event> mail_box;
  event_processor ep;

  btype _type;
  int _id;
};

#endif //BOMBERMAN_HPP
