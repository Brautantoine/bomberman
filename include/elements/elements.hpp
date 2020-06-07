#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

enum e_type
{
  PC = 1,
  NPC = 2,
  BLOCK = 3,
  UBLOCK,
  BOMBE,
};

class elements
{
public:
  virtual e_type get_type() = 0;
  virtual bool check_collision(int x, int y) = 0;
protected:
  e_type etype;
};

#endif //ELEMENTS_HPP
