#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <SFML/Window/Event.hpp>

#include <vector>
#include <mutex>
#include <chrono>
#include <thread>
#include <iostream>

#include "utils/simple_mail_box.hpp"
#include "events/event_watcher.hpp"
#include "events/event.hpp"

class event_manager
{

public:
  static event_manager* getInstance();
  virtual ~event_manager();

  void register_watcher(event_watcher* e);
  void unregister_watcher(event_watcher* e);
  void poll_event();
  void join() {manager_thread.join();}

  simple_mail_box<game_event::event>& get_mail_box() {return mail_box;}
protected:
private:
  static event_manager* instance;

  simple_mail_box<game_event::event> mail_box;
  std::mutex internal_lock;
  std::vector<event_watcher*> watchers;

  bool running;

  std::thread manager_thread;

  event_manager();


};

#endif //EVENT_MANAGER_HPP
