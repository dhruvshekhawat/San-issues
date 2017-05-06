#include <thread>
#include <atomic>
struct spin {
  void lock() {
    while (flag.test_and_set(std::memory_order_acquire))
      ;
  }

  void unlock() { flag.clear(std::memory_order_release); }

  std::atomic_flag flag = ATOMIC_FLAG_INIT;
};

int main() {
  int counter = 0;
  spin lock;

  std::thread t([&]() {
    lock.lock();
    ++counter;
    lock.unlock();
  });

  lock.lock();
  ++counter;
  lock.unlock();

  t.join();
  return 0;
}
