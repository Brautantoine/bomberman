#ifndef GAMECORE_HPP
#define GAMECORE_HPP

#include "events/event_processor.hpp"
#include "elements/elements.hpp"
#include "elements/bomberman.hpp"
#include "elements/npc.hpp"
#include "graphics/background.hpp"
#include "elements/block.hpp"

#include <vector>

typedef std::vector<std::vector<e_type>> e_matrix;

class gamecore
{

public:
  gamecore();
  virtual ~gamecore();
  void run();
protected:
private:
  std::vector<bomberman*> bmans;
  std::vector<elements*> blocks;

  bool core;

};


#endif //GAMECORE_HPP
