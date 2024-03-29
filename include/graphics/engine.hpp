#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "imgui.h"
#include "imgui-SFML.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <time.h>
#include <limits.h>

#include <thread>
#include <iostream>

#include "graphics/layout_manager.hpp"
#include "events/event_manager.hpp"
#include "events/event.hpp"
#include "utils/simple_mail_box.hpp"

#include <X11/Xlib.h>

#define SCREEN_W 480
#define SCREEN_H 640

//typedef unsigned long long frame_timer;
typedef struct _frame_timer
{
  unsigned long long  cc;
  unsigned long long  lc;
  unsigned long long  elapsed;
  bool  reset;
}frame_timer;

enum direction
{
  UP,
  LEFT,
  RIGHT,
  DOWN,
  STOP,
};

struct raw_key_input
{
  direction arrow;
  direction zqsd;
};

class engine
{

public:

  static engine* getInstance();
  virtual ~engine();
  unsigned long long get_frame_count() {return frame_count;}
  unsigned long long get_elapsed_frame(frame_timer* timer);
  bool is_running() {return running;}
  void join() {engine_thread.join();}
  void close();
  raw_key_input get_input(){return raw;}

  int dir;

protected:
private:
  static engine* instance;
  sf::RenderWindow window;
  std::thread engine_thread;
  layout_manager* lm;
  event_manager* em;
  simple_mail_box<game_event::event>& mail_box;

  unsigned long long frame_count;
  raw_key_input raw;

  bool running;


  engine();
  void run();

};

#endif //ENGINE_HPP
