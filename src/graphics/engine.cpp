#include "graphics/engine.hpp"

engine* engine::instance = NULL;

engine* engine::getInstance()
{
  if(!instance)
    instance = new engine();

  return instance;
}

engine::engine() : window(sf::VideoMode(640, 480), "Bomberman"), em(event_manager::getInstance()), mail_box(em->get_mail_box())
{
  window.setVerticalSyncEnabled(true);
  window.setFramerateLimit(60);
  ImGui::SFML::Init(window);

  lm = layout_manager::getInstance();

  running = true;

  engine_thread = std::thread(&engine::run,this);
}

engine::~engine()
{

}

void engine::run()
{
  //static bool show_shape(true);
  //sf::CircleShape shape(100.f);
  //shape.setFillColor(sf::Color::Green);

  srand(time(NULL));

  sf::Clock deltaClock;
  std::cerr << "engine running" << std::endl;
  while(running)
  {
      // Event management
      sf::Event event;
      while (window.pollEvent(event)) {
          ImGui::SFML::ProcessEvent(event);

          game_event::event e = {.type = SFML_EVENT, .event=event};
          mail_box.send(e);

          if (event.type == sf::Event::Closed) {
              window.close();
              game_event::event e = {.type = CLOSE};
              mail_box.send(e);
              em->join();
              running = false;


          //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            //std::cerr << "up" << '\n';
      }
    }
    //std::cerr << "finish poll" << '\n';

      // Graphic render
        // Debug test
      ImGui::SFML::Update(window, deltaClock.restart());

      ImGui::Begin("Hello, world!",NULL,ImGuiWindowFlags_NoResize);
      if(ImGui::Button("Look at this pretty button"))
        ;
//test_scope();
      ImGui::End();

      window.clear(sf::Color(0xCE, 0xCE, 0xCE));

      /*if(show_shape)
        window.draw(shape);*/

      // Real part with the draw callback
      std::vector<drawable*> drawables = lm->getDrawables();

      for(drawable* d : drawables)
      {
        d->draw(window);
      }


      ImGui::SFML::Render(window);

      window.display();
      frame_count++;
  }
}

unsigned long long engine::get_elapsed_frame(frame_timer* timer)
{
  timer->lc = timer->cc;
  unsigned long long fc = get_frame_count();
  if (timer->cc == fc)
  {
    timer->elapsed = 0;
    return 0;
  }

  return timer->cc <= fc ?
    [&](){timer->elapsed=fc-timer->cc;
          timer->reset = false;
          timer->cc = fc;
          return timer->elapsed;}() :
    [&](){int dif = ULLONG_MAX - timer->cc;
          timer->cc=fc;
          timer->reset = true;
          timer->elapsed =fc+dif;
          return timer->elapsed;}();
}
