#include "elements/bomberman.hpp"

bomberman::bomberman(btype type, int id) : _type(type), _id(id), ep(NONE,[](void*){})
{
  auto catch_event = [&](void* data)
  {
    //std::cerr << "my bad" << '\n';
    sf::Event e = ((game_event::event*)data)->event;
    if(e.type == sf::Event::KeyPressed)
    {
      switch(e.key.code)
      {
        case sf::Keyboard::Up :
        case sf::Keyboard::Down :
        case sf::Keyboard::Left :
        case sf::Keyboard::Right:
        case sf::Keyboard::Z:
        case sf::Keyboard::Q:
        case sf::Keyboard::S:
        case sf::Keyboard::D:
          std::cerr << "input detected" << '\n';
          mail_box.send(e);
        default:
          break;
      }
      /*if(e.key.code == sf::Keyboard::Up)
      {
        mail_box.send(sf::Keyboard::Up)
      }*/
    }
  };

  etype = character;

  switch(_type)
  {
    case PC:
      ep = event_processor(KEYBOARD,catch_event);
      break;
    case NPC:
      ep = event_processor(GENERATED_INPUT,catch_event);
      break;
  }
}

bomberman::~bomberman()
{

}
