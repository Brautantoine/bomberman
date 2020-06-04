#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

enum e_type
{
  PC,
  NPC,
  BLOCK,
  UBLOCK,
  BOMBE,
};

class elements
{
public:
  virtual e_type get_type() {return etype;}
protected:
  e_type etype;
};

#endif //ELEMENTS_HPP
