#ifndef EVENT_HPP
#define EVENT_HPP

#include "events/event_type.hpp"
#include <SFML/Window/Event.hpp>


namespace game_event
{

  struct internal_event
  {
    int a;
  };
  struct event
  {
    event_type type;
    sf::Event event;
    internal_event ievent;
  };
}

#endif //EVENT_HPP
