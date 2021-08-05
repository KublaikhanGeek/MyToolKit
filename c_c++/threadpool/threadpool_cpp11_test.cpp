#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>

#include "threadpool_cpp11.h"

int sum(int a, int b) {
  int c = a + b;
  std::cout << c << std::endl;
  return c;
}

int main() {

  // std::function<void()> tmp;
  // tmp = std::move(std::bind(sum, 1, 1));

  ThreadPool pool(4);
  std::vector<std::future<int>> results;

#if 0
  for (int i = 0; i < 8; ++i) {
    results.emplace_back(pool.enqueue([i] {
      // std::cout << "thread: " << std::this_thread::get_id() << " hello " << i
      // << std::endl;
      //      std::this_thread::sleep_for(std::chrono::seconds(1));
      // std::cout << "thread: " << std::this_thread::get_id() << " world " << i
      // << std::endl;
      // std::cout << i << std::endl;
      std::ostringstream ss;
      ss << "thread: " << std::this_thread::get_id() << " hello " << i
         << std::endl;
      std::cout << ss.str() << std::endl;
      return i * i;
    }));
#endif
  for (int i = 0; i < 8; ++i) {
    results.emplace_back(pool.enqueue(sum, i, i));
  }

  for (auto &&result : results)
    std::cout << "future: " << result.get() << ' ';

  std::cout << std::endl;

  return 0;
}
