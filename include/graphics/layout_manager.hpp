#ifndef LAYOUT_MANAGER_HPP
#define LAYOUT_MANAGER_HPP

// NOT IMPLEMENTED YET, CAN AND WILL CAUSE RACE CONDITIONS

#include <vector>
#include <mutex>

#include "graphics/drawable.hpp"

class layout_manager
{

public:
  static layout_manager* getInstance();
  virtual ~layout_manager();

  std::vector<drawable*> getDrawables();
  void registerDrawable(drawable* d);
  void unregisterDrawable(drawable* d);
protected:
private:
  static layout_manager* instance;

  std::mutex internal_lock;
  std::vector<drawable*> drawables;

  layout_manager();

  void quick_sort(int start, int end);
  int partition(int start, int end);

};

#endif //LAYOUT_MANAGER_HPP
