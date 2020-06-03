#ifndef EVENT_PROCESSOR_HPP
#define EVENT_PROCESSOR_HPP

#include "events/event.hpp"
#include "events/event_watcher.hpp"
#include "events/event_manager.hpp"

#include <functional>

class event_processor : public event_watcher
{
public:
  event_processor(event_type expected, std::function<void(void* )> func) : _expected(expected), _func(func)
  {
    em = event_manager::getInstance();
    //std::cerr << "crash ?" << '\n';
    em->register_watcher(this);
    //std::cerr << "no" << '\n';
  }
  ~event_processor()
  {
    //std::cerr << "crash ?" << '\n';
    em->unregister_watcher(this);
    //std::cerr << "no" << '\n';
  }
  event_type validate() {return _expected;}
  void notify(void* data){_func(data);}
protected:
private:

  event_type _expected;
  std::function<void(void *)> _func;
  event_manager* em;

};

#endif //EVENT_PROCESSOR_HPP
