#include "elements/bombe.hpp"

bombe::bombe()
{
  //std::cerr << "constr called" << '\n';
  if(!texture.loadFromFile("ressources/img/bomb.png"))
    throw std::runtime_error("can't load bomb.png");
  if(!etexture.loadFromFile("ressources/img/explosion.png"))
    throw std::runtime_error("can't load explosion.png");
  sprite.setTexture(texture);
  //sprite.setPosition(x,y);
  //layout_manager::getInstance()->registerDrawable(this);

  update_count = 0;
  frame_count = 0;
  range = 3;

  l_stop = false;
  r_stop = false;
  u_stop = false;
  d_stop = false;

  etype = BOMBE;

  active = false;
}

bombe::~bombe()
{
  if(active)
    layout_manager::getInstance()->unregisterDrawable(this);
}


void bombe::draw(sf::RenderWindow& w)
{
  //std::cerr << "draw called for bombe" << '\n';
  w.draw(sprite);
  for(sf::Sprite s : esprites)
  {
    w.draw(s);
  }
}

void bombe::spawn(int x, int y)
{
  if(!active)
  {
    l_stop = false;
    r_stop = false;
    u_stop = false;
    d_stop = false;

    std::cerr << "register bomb in " << x <<":"<<y << '\n';
    center_x = x + (SPRITE_W/2);
    center_y = y + (SPRITE_H/2);
    std::cerr << "centered in " << center_x << ":" << center_y << '\n';
    sprite.setPosition(x,y);
    layout_manager::getInstance()->registerDrawable(this);

    update_count = 0;
    frame_count = 0;
    esprites.clear();
    active = true;
  }


}

bool bombe::update(std::vector<bomberman*>& bmans, std::vector<elements*>& blocks, std::vector<elements*>& affected)
{
  if(update_count<40) // 2 sec delay
  {
    update_count++;
    return false;
  }
  else if(active)
  {
    affected.clear();
    bool first_case = false;
    for(bomberman * b : bmans)
    {
        if(!(b->check_collision(center_x,center_y)))
        {
            affected.push_back(b);
            first_case = true;
        }
        sf::Sprite s;
        s.setTexture(etexture);
        s.setPosition(center_x - (SPRITE_W/2),center_y - (SPRITE_H/2));
          esprites.emplace_back(s);
        //  *(esprites.end())
        //  *(esprites.end())
    }
    if(!first_case)
    {
      std::cerr << "start recusrion" << '\n';
        find_affected(bmans,blocks,affected,1);
    }
    update_count = 0;
    return true;
  }

}
void bombe::vanish()
{
  if(active)
  {
    layout_manager::getInstance()->unregisterDrawable(this);
    active = false;
  }

}

void bombe::find_affected(std::vector<bomberman*>& bmans, std::vector<elements*>& blocks, std::vector<elements*>& affected,int index)
{
  if(index <= range)
  {
    for(bomberman* b : bmans)
    {
      if(!l_stop)
        if(!(b->check_collision(center_x-SPRITE_W*index+5,center_y)))
          affected.push_back(b);
      if(!r_stop)
        if(!(b->check_collision(center_x+SPRITE_W*index-5,center_y)))
          affected.push_back(b);
      if(!u_stop)
        if(!(b->check_collision(center_x,center_y-SPRITE_H*index+5)))
          affected.push_back(b);
      if(!d_stop)
        if(!(b->check_collision(center_x,center_y+SPRITE_H*index-5)))
          affected.push_back(b);
    }
    for(elements* e : blocks)
    {
      if(!l_stop)
      {
        if((!(e->check_collision(center_x-SPRITE_W*index+5,center_y))))
        {
          if(e->get_type() == BLOCK)
            affected.push_back(e);
          l_stop = true;
        }

        sf::Sprite s;
        s.setTexture(etexture);
        s.setPosition(center_x - (SPRITE_W/2)-SPRITE_W*index,center_y - (SPRITE_H/2));
          esprites.emplace_back(s);
      }


      if(!r_stop)
      {
        if(!(e->check_collision(center_x+SPRITE_W*index-5,center_y)))
        {
          if(e->get_type() == BLOCK)
            affected.push_back(e);
          r_stop = true;
        }
        sf::Sprite s;
        s.setTexture(etexture);
        s.setPosition(center_x - (SPRITE_W/2)+SPRITE_W*index,center_y - (SPRITE_H/2));
          esprites.emplace_back(s);
      }

      if(!u_stop)
      {
        if(!(e->check_collision(center_x,center_y-SPRITE_H*index+5)))
        {
          if(e->get_type() == BLOCK)
            affected.push_back(e);
          u_stop = true;
        }
        sf::Sprite s;
        s.setTexture(etexture);
        s.setPosition(center_x - (SPRITE_W/2),center_y - (SPRITE_H/2)-SPRITE_H*index);
          esprites.emplace_back(s);
      }

      if(!d_stop)
      {
        if(!(e->check_collision(center_x,center_y+SPRITE_H*index-5)))
        {
          if(e->get_type() == BLOCK)
            affected.push_back(e);
          d_stop = true;
        }
        sf::Sprite s;
        s.setTexture(etexture);
        s.setPosition(center_x - (SPRITE_W/2),center_y - (SPRITE_H/2)+SPRITE_H*index);
          esprites.emplace_back(s);
      }

    }
    find_affected(bmans,blocks,affected,++index);
  }
}
