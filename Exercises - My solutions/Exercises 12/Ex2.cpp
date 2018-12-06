#include <iostream>
  int& fun() {
    static int x = 10;
    return x;
  }

  int main(void) {
  std::cout << fun() << std::endl;
  fun() = 30;
  std::cout << fun() << std::endl;
  return 0;
  }
