// TOPIC: std::future and std::promise in threading

//NOTES
// 1. std::promise
//    a. Used to set values or exceptions


// 2. std::future
//    a. Used to get values from promise 
//    b. Ask promise if the value is available
//    c. Wait for the promise


#include <thread>
#include <chrono>
#include <future>
#include <algorithm>
#include <iostream>

using namespace std;
using namespace std::chrono;
typedef long int ull;

void findOdd(std::promise<ull>&& OddSumPromise, ull start, ull end) {
	ull OddSum = 0;
	for (ull i = start; i <= end; ++i) {
		if (i & 1) {
			OddSum += i;
		}
	}
	OddSumPromise.set_value(OddSum);
	
}

int main() {
	
	ull start = 0;
	ull end = 1900000000;
	
	// there is a state sharing between st::promise and std::future
	
	std::promise<ull> OddSum; //promise object 
	std::future<ull> OddFuture = OddSum.get_future(); //future object 
	
	cout << "Thread Created" << endl;
	std::thread t1(findOdd, std::move(OddSum), start, end);	//function pointer
	
	cout << "Waiting for result" << endl;
	
	cout << "OddSum :" << OddFuture.get() << endl;
	
	cout << " Completed" << endl;
	
	t1.join();
	
	return 0;
	
}			
