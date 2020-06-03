#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>


class drawable
{
public:
   virtual void draw(sf::RenderWindow& w)=0;
   virtual int getLayer()=0;
};

#endif //DRAWABLE_HPP
