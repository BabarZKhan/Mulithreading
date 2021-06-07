#include <future>
#include <iostream>
#include <thread>

int main()
{

    std::cout << std::endl;
    int res;
    std::thread t([&] { res = 2000 + 11; }); // "res" is shared variable
    t.join(); // t: the child thread
    std::cout << "res: " << res << std::endl; // the creator thread gets the result from child thread t via the shared varibale res
     
    auto fut = std::async([] { return 2000 + 11; });
    std::cout << "fut.get(): " << fut.get() << std::endl; //fut.get is blocking call
    std::cout << std::endl;
}
