#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::mutex coutMutex;

class Worker {

public:
  Worker(std::string n) : name(n){};

  void operator()() {

    for (int i = 0; i <= 3; ++i) {

      // begin work

      std::this_thread::sleep_for(std::chrono::milliseconds(200));

      // end work

      coutMutex.lock();
      std::cout << name << ":"
                << "Work " << i << " done " << std::endl;
      coutMutex.unlock();
      // a simple lock and unlock to make sure that factor workers don't screan
      // at once
    }
  }

private:
  std::string name;
};

int main() {

  std::cout << std::endl;
  std::cout << "Lets start working"
            << "\n\n";

  // by the way, std::cout is thread safe

  std::thread factoryWorkerOne = std::thread(Worker("factoryWorkerOne"));
  std::thread factoryWorkerTwo = std::thread(Worker("factoryWorkerTwo"));
  std::thread factoryWorkerThree = std::thread(Worker("factoryWorkerThree"));
  std::thread factoryWorkerFour = std::thread(Worker("factoryWorkerFour"));
  std::thread factoryWorkerFive = std::thread(Worker("factoryWorkerFive"));
  std::thread factoryWorkerSix = std::thread(Worker("factoryWorkerSix"));

  factoryWorkerOne.join();
  factoryWorkerTwo.join();
  factoryWorkerThree.join();
  factoryWorkerFour.join();
  factoryWorkerFive.join();
  factoryWorkerSix.join();

  std::cout << "lets go home" << endl;

  std::cout << std::endl;
}