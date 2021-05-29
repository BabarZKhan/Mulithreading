#include <iostream>
#include <thread>

void foo() { std::cout << "My name is foo..\n"; }

int main() {

  std::thread t(foo);
  t.join();
}
