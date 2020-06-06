#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics/drawable.hpp"
#include "graphics/layout_manager.hpp"

#include <functional>

class widget : virtual drawable
{
public:
  widget(std::function<void()> func) : _func(func) {layout_manager::getInstance()->registerDrawable(this);};

  void draw(sf::RenderWindow& w){_func();}
  int getLayer(){return 99;}

  void vanish() {layout_manager::getInstance()->unregisterDrawable(this);}

private:
  std::function<void()> _func;
};

#endif //WIDGET_HPP
