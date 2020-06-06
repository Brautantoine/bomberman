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

  bool spawn_b_1 = false;
  bool spawn_b_2 = false;

  volatile bool menu_on = true;
  volatile int nb_pc = 0;

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
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));

  /*blocks.emplace_back("ressources/img/ublock.png",SPRITE_H*-1,SPRITE_W*-1,UBLOCK);
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
  blocks.emplace_back("ressources/img/ublock.png",SPRITE_H*-1,SPRITE_W*-1,UBLOCK);
  std::this_thread::sleep_for(std::chrono::milliseconds(50));*/

  //block bl("ressources/img/block.png",SPRITE_H*8,SPRITE_W*9,BLOCK);
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));
  //block ubl("ressources/img/ublock.png",SPRITE_H*0,SPRITE_W*0,UBLOCK);
  /*bblocks[0]*///block* bb = new block("ressources/img/ublock.png",SPRITE_H*7,SPRITE_W*2,UBLOCK);
  //block* bb = bblocks;
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));

//std::cerr << "emplace" << '\n';
blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*1,SPRITE_W*1,UBLOCK));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*2,SPRITE_W*4,UBLOCK));
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));
  blocks.push_back(new block("ressources/img/ublock.png",SPRITE_H*3,SPRITE_W*3,UBLOCK));
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*5,SPRITE_W*7,BLOCK));
  //std::this_thread::sleep_for(std::chrono::milliseconds(50));
  blocks.push_back(new block("ressources/img/block.png",SPRITE_H*8,SPRITE_W*1,BLOCK));
//  std::this_thread::sleep_for(std::chrono::milliseconds(50));


/*std::cerr << "start registering" << '\n';
  for(block b : blocks)
  {
    std::cerr << "self register for " << &b << '\n';
    b.self_register();
  }*/

//std::cerr << "bman" << '\n';

  std::cerr << "size :" << blocks.size() << '\n';
  while(core)
  {
    //bman.update(blocks);
    //bman2.update(blocks);

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
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}
