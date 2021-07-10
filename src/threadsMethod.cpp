
// threadMethods.cpp

// t.join : waits until thread t


#include <iostream>
#include <thread>

using namespace std;

int main()
{

    cout << boolalpha << endl;

    cout << "hardware_concurrency()= " << thread::hardware_concurrency() << endl;
    thread t1([] { cout << "t1 with id= " << this_thread::get_id() << endl; }); // returns the id of the thread
    thread t2([] { cout << "t2 with id= " << this_thread::get_id() << endl; }); //returns the id of the thread
    cout << endl;
    cout << "FROM MAIN: id of t1 " << t1.get_id() << endl;
    cout << "FROM MAIN: id of t2 " << t2.get_id() << endl;
    cout << endl;
    swap(t1, t2);
    cout << "FROM MAIN: id of t1 " << t1.get_id() << endl;
    cout << "FROM MAIN: id of t2 " << t2.get_id() << endl;
    cout << endl;
    cout << "FROM MAIN: id of main= " << this_thread::get_id() << endl;
    cout << endl;
    cout << "t1.joinable(): " << t1.joinable() << endl; //return true if thread t is still joinable
    cout << endl;
    t1.join();
    t2.join();

    cout << endl;
    cout << "t1.joinable(): " << t1.joinable() << endl;
    cout << endl;
}
