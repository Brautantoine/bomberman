#include "utils/simple_mail_box.hpp"

/*template <typename T>
simple_mail_box<T>::simple_mail_box() {}
template <typename T>
simple_mail_box<T>::~simple_mail_box() {}*/

template <typename T>
void simple_mail_box<T>::send(const T& data)
{
  std::unique_lock<std::mutex> _lock(internal_lock);
  fifo.emplace(data);
  _lock.unlock();
}

template <typename T>
const T& simple_mail_box<T>::receive()
{
  std::unique_lock<std::mutex> _lock(internal_lock);
  if(fifo.empty())
    throw std::runtime_error("invalid call of receive");
  const T& data = fifo.front();
  fifo.pop();
  _lock.unlock();
  return data;
}
