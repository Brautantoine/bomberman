#ifndef NPC_HPP
#define NPC_HPP

#include "elements/bomberman.hpp"

#include <cstdlib>
#include <ctime>

class npc : public bomberman
{
  using bomberman::bomberman;
  public:
     void update(std::vector<elements*> e);
};

#endif //NPC_HPP
