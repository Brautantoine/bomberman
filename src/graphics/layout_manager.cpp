#include "graphics/layout_manager.hpp"

layout_manager* layout_manager::instance = 0;

layout_manager::layout_manager()
{

}

layout_manager::~layout_manager()
{

}

layout_manager* layout_manager::getInstance()
{
  if(!instance)
    instance = new layout_manager();

  return instance;
}

std::vector<drawable*> layout_manager::getDrawables()
{

  std::unique_lock<std::mutex> _lock (internal_lock);
  auto drawables_copy(drawables);
  _lock.unlock();
  return drawables_copy;
  //return std::vector<drawable*>();
}

void layout_manager::registerDrawable(drawable* d)
{
std::unique_lock<std::mutex> _lock (internal_lock);
std::cerr << "nf of drawables before emplace" << drawables.size() << '\n';
  drawables.push_back(d);
  std::cerr << "nf of drawables" << drawables.size() << '\n';
  quick_sort(0,drawables.size()-1);
  std::cerr << "nf of drawables after quicksort" << drawables.size() << '\n';

  /*for(drawable* p : drawables)
    std::cerr << "layer : " << p->getLayer() << '\n';*/

  _lock.unlock();
}

void layout_manager::unregisterDrawable(drawable* d)
{
  bool internal_check = true;
std::cerr << "unregister called for " << d << '\n';

  std::unique_lock<std::mutex> _lock (internal_lock);

  /*for(auto it = drawables.begin(); it!=drawables.end(); ++it)
  {
    if(d == *it)
    {
      drawables.erase(it);
      internal_check = true;
    }
  }*/
  std::cerr << "nb of sprite before remove" << drawables.size() << '\n';
  drawables.erase(std::remove(drawables.begin(), drawables.end(),d), drawables.end());
  std::cerr << "nb of sprite after remove" << drawables.size() << '\n';

  _lock.unlock();

  if(!internal_check)
    throw std::runtime_error("Enable to locate and unregister drawable");

}

void layout_manager::quick_sort(int start, int end)
{
  if (start < end) {
			int pivot = partition(start, end);
			quick_sort(start, pivot);
			quick_sort(pivot + 1, end);
		}
}

int layout_manager::partition(int start, int end)
{
  int pivot_point = drawables.at(start + (end - start) / 2)->getLayer();
		int left = start - 1;
		int right = end + 1;
		while (true) {
			do {
				left++;
			} while (drawables.at(left)->getLayer() < pivot_point);
			do {
				right--;
			} while (drawables.at(right)->getLayer() > pivot_point);
			if (left >= right) {
				return right;
			}
			std::swap(drawables.at(left),drawables.at(right));
    }
}
