/* Future:
 * Async programming
 * Without creating exxplicit threads
 */ 



#include <thread>
#include <future>
#include <iostream>

using namespace std;
/*
void asyncFunc() {

  cout<<"Async Thread"<<this_thread::get_id()<<endl;
  cout<<"I am inside async"<<endl;
}

int main () {

   cout<<"Main thread"<<this_thread::get_id()<<endl;
   future<void> fn  = async(launch::async, asyncFunc);
 
  
   fn.get();
   return 0;
}
*/

/*
int asyncFunc() {

  cout<<"Async Thread"<<this_thread::get_id()<<endl;
  cout<<"I am inside async"<<endl;
  
  return 100;
}

int main () {

   cout<<"Main thread"<<this_thread::get_id()<<endl;
   future<int> fn  = async(launch::async, asyncFunc);
 
  
   cout<<fn.get()<<endl;
   return 0;
}
*/




int asyncFunc(int value) {

  cout<<"Async Thread"<<this_thread::get_id()<<endl;
  cout<<"I am inside async"<<endl;
  
  return value + 100;
}

int main () {

   cout<<"Main thread"<<this_thread::get_id()<<endl;
   future<int> fn  = async(launch::async, asyncFunc, 200);
 
  
   cout<<fn.get()<<endl;
   return 0;
}






/* void asyncFunc() {

  cout<<"Async Thread"<<this_thread::get_id()<<endl;
  cout<<"I am inside async"<<endl;
} */

/* int main () {
   cout<<"Main thread"<<this_thread::get_id()<<endl;
   future<void> fn  = async(launch::deferred, asyncFunc);
   // what defer does? it calls asyncFun only when .get() is called
   // when we use defer, the thread of main asyncFunc will be same
   fn.get();
   return 0; } */
