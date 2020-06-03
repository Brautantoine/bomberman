#ifndef EVENT_WATCHER_HPP
#define EVENT_WATCHER_HPP

#include "events/event.hpp"

class event_watcher
{
public:
  virtual event_type validate()=0;
  virtual void notify(void* data)=0;
};

#endif //EVENT_WATCHER_HPP
