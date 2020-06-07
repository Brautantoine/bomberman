#include "game/gamecore.hpp"

gamecore::gamecore()
{
  core = true;
}

gamecore::~gamecore()
{

}

void gamecore::run()
{
  engine* p_e = engine::getInstance();

  bool spawn_b_1 = false;
  bool spawn_b_2 = false;

  int vanish_countdown_1 = 5;
  bool vanished_1 = true;

  int vanish_countdown_2 = 5;
  bool vanished_2 = true;

  volatile bool menu_on = true;
  volatile int nb_pc = 1;

  int id_winner(0);

  std::vector<elements*> affected;

  widget w([&](){ImGui::Begin("Bomberman v-1.0.0",NULL,ImGuiWindowFlags_NoResize);
  if(ImGui::Button("1 joueur"))
  {
    nb_pc = 1;
    menu_on = false;
  }
  if(ImGui::Button("2 joueur"))
  {
    nb_pc = 2;
    menu_on = false;
  }
//test_scope();
  ImGui::End();});


  //block bblocks[2];
  //std::cerr << "background" << '\n';
  background b("ressources/background/1.png");
  bombe bomb;
  bombe bomb2;
//std::this_thread::sleep_for(std::chrono::milliseconds(50));
  //bomberman bman(0);
  while(menu_on);

  w.vanish();

  event_processor ep(KEYBOARD,[&](void* data)
  {
    //std::cerr << "lambda called" << '\n';
    sf::Event e = ((game_event::event*)data)->event;
    if(e.type == sf::Event::KeyPressed)
    {
      if(e.key.code == sf::Keyboard::C)
      {
        std::cerr << "EVENT BOMBE P2" << '\n';
        spawn_b_2 = true;
        //bl.vanish();
      }
      else if(e.key.code == sf::Keyboard::Space)
      {
        std::cerr << "EVENT BOMBE P1" << '\n';
        spawn_b_1 = true;
      }
    }
  });

  bmans.push_back(new bomberman(0));
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));
  //bomberman bman2(1);
  if(nb_pc == 2)
    bmans.push_back(new bomberman(1));
  else
    bmans.push_back(new npc(1));

  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*1,SPRITE_W*1,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*3,SPRITE_W*0,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*6,SPRITE_W*0,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*5,SPRITE_W*1,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*8,SPRITE_W*1,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*3,SPRITE_W*2,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*7,SPRITE_W*2,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*1,SPRITE_W*3,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*5,SPRITE_W*3,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*8,SPRITE_W*3,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*3,SPRITE_W*4,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*7,SPRITE_W*4,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*1,SPRITE_W*5,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*5,SPRITE_W*5,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*8,SPRITE_W*5,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*9,SPRITE_W*5,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*3,SPRITE_W*6,UBLOCK));
  //blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*7,SPRITE_W*6,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*1,SPRITE_W*7,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*5,SPRITE_W*7,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*8,SPRITE_W*7,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*3,SPRITE_W*8,UBLOCK));
  //blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*7,SPRITE_W*8,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*8,SPRITE_W*8,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*1,SPRITE_W*9,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*5,SPRITE_W*9,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*8,SPRITE_W*9,UBLOCK));

  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*0,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*0,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*8,SPRITE_W*0,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*9,SPRITE_W*0,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*1,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*3,SPRITE_W*1,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*6,SPRITE_W*1,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*1,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*0,SPRITE_W*2,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*1,SPRITE_W*2,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*2,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*4,SPRITE_W*2,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*5,SPRITE_W*2,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*6,SPRITE_W*2,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*3,SPRITE_W*3,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*3,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*9,SPRITE_W*3,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*0,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*1,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*4,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*5,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*6,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*3,SPRITE_W*5,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*5,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*0,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*1,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*4,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*5,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*6,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*6,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*3,SPRITE_W*7,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*7,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*0,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*1,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*4,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*5,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*6,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*7,SPRITE_W*8,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*9,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*3,SPRITE_W*9,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*6,SPRITE_W*9,BLOCK));
  /*blocks.push_back(new block("ressources/img/block.png",SPRITE_H*2,SPRITE_W*4,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*3,SPRITE_W*3,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*5,SPRITE_W*7,BLOCK));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*8,SPRITE_W*1,BLOCK));*/


  std::cerr << "size :" << blocks.size() << '\n';
  while(core && p_e->is_running())
  {
    for(bomberman*  b : bmans)
      b->update(blocks);

    if(spawn_b_1)
    {
      std::cerr << "spawn_b_1" << '\n';
      spawn_b_1 = false;
      position p = bmans.at(0)->get_position();
      bomb.spawn(p.x,p.y);
      //blocks.push_back(new block("ressources/img/ublock.png",p.x,p.y,UBLOCK));
    }

    if(spawn_b_2)
    {
      std::cerr << "spawn_b_2" << '\n';
      spawn_b_2 = false;
      position p = bmans.at(1)->get_position();
      bomb2.spawn(p.x,p.y);
    }

    if(bomb.update(bmans,blocks,affected))
    {
      vanished_1 = false;
      vanish_countdown_1 = 5;
      //bomb.vanish();
      if(affected.size() > 0)
      {
        std::cerr << "affected detected :" << affected.size() << '\n';
        for(elements* e : affected)
        {
          std::cerr << "affected type :" << e->get_type() << '\n';
            if(e->get_type() == BLOCK)
            {
              std::cerr << "vanish block" << '\n';
              ((block*)e)->vanish();
              blocks.erase(std::remove(blocks.begin(),blocks.end(),e),blocks.end());
            }
            else if ((e->get_type() == PC) || (e->get_type() == NPC))
            {
              std::cerr << "bomberman touched, ending game ..." << '\n';
              id_winner = ((bomberman*)e)->get_id();
              core = false;
            }
        }
        affected.clear();
      }
    }

      if(bomb2.update(bmans,blocks,affected))
      {
        vanished_2 = false;
        vanish_countdown_2 = 5;
        //bomb.vanish();
        if(affected.size() > 0)
        {
          std::cerr << "affected detected :" << affected.size() << '\n';
          for(elements* e : affected)
          {
            std::cerr << "affected type :" << e->get_type() << '\n';
              if(e->get_type() == BLOCK)
              {
                std::cerr << "vanish block" << '\n';
                ((block*)e)->vanish();
                blocks.erase(std::remove(blocks.begin(),blocks.end(),e),blocks.end());
              }
              else if ((e->get_type() == PC) || (e->get_type() == NPC))
              {
                std::cerr << "bomberman touched, ending game ..." << '\n';
                id_winner = ((bomberman*)e)->get_id();
                core = false;
              }
          }
          affected.clear();
        }
    }


    if(!vanished_1)
    {
      if(vanish_countdown_1 <= 0)
      {
        vanished_1 = true;
        bomb.vanish();
      }
      else
      {
        vanish_countdown_1--;
      }
    }

    if(!vanished_2)
    {
      if(vanish_countdown_2 <= 0)
      {
        vanished_2 = true;
        bomb2.vanish();
      }
      else
      {
        vanish_countdown_2--;
      }
    }


    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }

  menu_on = true;

  std::ostringstream buffer;

  buffer << "joueur " << (id_winner == 1 ? 1 : 2) << " à gagné !";

  widget ew([&](){ImGui::Begin("Fin de la partie",NULL,ImGuiWindowFlags_NoResize);
  ImGui::Text(buffer.str().c_str());
  if(ImGui::Button("Ok"))
  {
    menu_on = false;
  }
//test_scope();
  ImGui::End();});

while(menu_on);
ew.vanish();


  for(bomberman* b : bmans)
  {
    delete b;
  }

  for(elements* e : blocks)
  {
    delete (block*)e;
  }


}
