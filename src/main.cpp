#include "imgui.h"
#include "imgui-SFML.h"
#include "utils/simple_mail_box.hpp"
#include "graphics/engine.hpp"
#include "graphics/dummy_sprite.hpp"
#include "events/event_processor.hpp"
#include "elements/bomberman.hpp"
#include "elements/block.hpp"
#include "graphics/background.hpp"
#include "game/gamecore.hpp"

#include <iostream>
#include <thread>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <time.h>
#include <limits.h>

#include <unistd.h>

void test_scope();

int main()
{
    frame_timer f = {0,0,0,false};
    engine* e = engine::getInstance();
    //layout_manager* lm = layout_manager::getInstance();
    //dummy_sprite d(1);
    /*dummy_sprite dd(5);
    dummy_sprite ddd(2);
    dummy_sprite erd(4);*/
    //lm->registerDrawable(&d);
    //lm->registerDrawable(&dd);
    //lm->registerDrawable(&ddd);
    //lm->registerDrawable(&erd);
    /*background b("ressources/background/1.png");
    block bl("ressources/img/block.png",SPRITE_H*8,SPRITE_W*9,BLOCK);
    block ubl("ressources/img/ublock.png",SPRITE_H*0,SPRITE_W*0,UBLOCK);*/



    /*event_processor ep(KEYBOARD,[&](void* data)
    {
      //std::cerr << "lambda called" << '\n';
      sf::Event e = ((game_event::event*)data)->event;
      if(e.type == sf::Event::KeyPressed)
      {
        if(e.key.code == sf::Keyboard::Up)
        {
          std::cerr << "UP" << '\n';
          //bl.vanish();
        }
      }
    });

    event_processor ep2(KEYBOARD,[&](void* data)
    {
      //std::cerr << "lambda called" << '\n';
      sf::Event e = ((game_event::event*)data)->event;
      if(e.type == sf::Event::KeyPressed)
      {
        if(e.key.code == sf::Keyboard::Q)
        {
          std::cerr << "DOWN" << '\n';
          //lm->unregisterDrawable(&d);
        }
      }
    });*/

    //bomberman bman(0);
    //bomberman bman2(1);

    gamecore g;
    g.run();

    std::cout << "ft :" << f.cc << " and " << e->get_elapsed_frame(&f) << "with" << e->get_frame_count() << '\n';
    //sleep(1);
    std::cout << "ft :" << f.cc << " and " << e->get_elapsed_frame(&f) << "with" << e->get_frame_count() << '\n';
    //sleep(2);
    std::cout << "ft :" << f.cc << " and " << e->get_elapsed_frame(&f) << "with" << e->get_frame_count() << '\n';

    //while(e->is_running())
      //std::this_thread::sleep_for(std::chrono::milliseconds(100));

    /*while(1)
    {
      bman.update();
      bman2.update();
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }*/

    e->join();
}
