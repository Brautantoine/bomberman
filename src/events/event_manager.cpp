#include "events/event_manager.hpp"

event_manager* event_manager::instance = 0;

event_manager::event_manager()
{
  running = true;
  manager_thread = std::thread(&event_manager::poll_event, this);
}

event_manager::~event_manager()
{
  running = false;
}

event_manager* event_manager::getInstance()
{
  if(!instance)
    instance = new event_manager();

  return instance;
}

void event_manager::register_watcher(event_watcher* e)
{
  std::unique_lock<std::mutex> _lock (internal_lock);
  watchers.emplace_back(e);
  _lock.unlock();
}

void event_manager::unregister_watcher(event_watcher* e)
{
  bool internal_check = true;

  // TODO BUGGED

  std::unique_lock<std::mutex> _lock (internal_lock);
  /*for(auto it = watchers.begin(); it!=watchers.end(); it++)
  {
    if(e == *it)
    {
      watchers.erase(it);
      internal_check = true;
    }
  }*/
  watchers.erase(std::remove(watchers.begin(), watchers.end(), e), watchers.end());

  _lock.unlock();

  if(!internal_check)
    throw std::runtime_error("Enable to locate and unregister watcher");

}

void event_manager::poll_event()
{
  std::cout << "Event manager started" << '\n';
  while(running)
  {
    while(!mail_box.empty())
    {
      //std::cerr << "new Event" << '\n';
      game_event::event ne = mail_box.receive();

      if(ne.type == SFML_EVENT)
      {
        //std::cerr << "it will crash" << '\n';
        /*sf::Event e = ne.event;
        if(e.type == sf::Event::KeyPressed)
        if(e.key.code == sf::Keyboard::Up)
          std::cerr << "UP" << '\n';*/
        if(ne.event.type == sf::Event::KeyPressed){
          //std::cerr << "hey" << '\n';
          std::for_each(watchers.begin(), watchers.end(), [&](event_watcher* n){if(KEYBOARD == n->validate())n->notify(&ne);});
        }
      }
      else if(ne.type == CLOSE)
      {
        running = false;
      }

    }

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
  }
}
