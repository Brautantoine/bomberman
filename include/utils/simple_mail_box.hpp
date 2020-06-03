#ifndef SIMPLE_MAIL_BOX_HPP
#define SIMPLE_MAIL_BOX_HPP

#include <mutex>
#include <queue>

template <typename T>
class simple_mail_box
{
public:
  //simple_mail_box();
  //~simple_mail_box();

  void send(const T& data);
  const T& receive();
  bool empty() {return fifo.empty();}
protected:

private:
  std::mutex internal_lock;
  std::queue<T> fifo;
};

#include "../src/utils/simple_mail_box_impl.hpp"

#endif //SIMPLE_MAIL_BOX_HPP
