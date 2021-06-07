
// TOPIC : async

// NOTES:
// 1. It runs a function asynchronously (potentially in a new thread) and returns std::future
//    that will hold the result.

// 2. There are three launch policies for creating tasks:
//    a. std::launch ::async
//    b. std::launch::defered      
//    c. std::launch::async | std::launch::async 



//std:async feels like an asynchronous function call. Under the hood std::async is a task. One, which is extremely easy to use

#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <future>
#include <algorithm>

using namespace std;
using namespace std::chrono;
typedef long int ull;


ull findOdd(ull start, ull end) {
	ull OddSum = 0;
	cout << "Thread ID of function findOdd is: " <<std::this_thread::get_id() << endl;
	for (ull i= start; i<= end; i++) {
		if (i & 1) {
			OddSum += i;
		}
	}
	return OddSum;
}

int main () {
	
	ull start = 0, end = 1900000000;
	
	cout << "Thread ID of fmain () function is: " <<std::this_thread::get_id() << endl;
	cout << "Thread created if policy is std::launch::async!" << endl;		
    std::future<ull> OddSum = std::async(std::launch::deferred, findOdd, start, end);
    
    cout <<"Waiting for Result" << endl;
    cout << "OddSum : " << OddSum.get() << endl;
    
    cout << "Completed" << endl;
    return 0;
}
