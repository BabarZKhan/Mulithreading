
// Ways to create threads in C+11
// 1. Function Pointers 
// 2. Lambda Functions
// 3. Functors
// 4. Member Functions
// 5. Static member functions

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;
typedef long long int  ull;

void findEven(ull start, ull end, ull* EvenSum) {
	for (ull i = start; i <= end; ++i){
		if (!(i & 1)){
			*(EvenSum) += i;
		}
	}
}

void findOdd(ull start, ull end, ull* OddSum) {
	for (ull i = start; i <= end; ++i){
		if (i & 1){
			(*OddSum) += i;
		}
	}
}


// THREADING-SWITCH = ON

int main() {
	
	ull start = 0, end = 1900000000;

	ull OddSum = 0;
	ull EvenSum = 0;
    
    
    auto startTime = high_resolution_clock::now();  
	
	// two threads
    std::thread t1(findEven, start, end, &(EvenSum));
    std::thread t2(findOdd, start, end, &(OddSum));

   
    //joining the thread. If we don't use join then thread t1 and thread t2 will not join the main thread int main
	t1.join();
	t2.join();
  
	

    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);
	
	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;
	cout << "Sec: " << duration.count()/1000000 << endl;
	return 0;
}


// THREADING-SWITCH = OFF



/*
ull OddSum = 0;
ull EvenSum = 0;

void findEven(ull start, ull end) {
	for (ull i = start; i <= end; ++i){
		if (!(i & 1)){
		     EvenSum += i;
		}
	}
}

void findOdd(ull start, ull end) {
	for (ull i = start; i <= end; ++i){
		if (i & 1){
			OddSum += i;
		}
	}
}

int main() {
	
	ull start = 0, end = 1900000000;

    
	// WITHOUT THREAD
	
	auto startTime = high_resolution_clock::now();
	findEven(start, end);
	findOdd (start, end);
    auto stopTime = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stopTime - startTime);

	cout << "OddSum : " << OddSum << endl;
	cout << "EvenSum : " << EvenSum << endl;
    cout << "Sec: " << duration.count()/1000000 << endl;

	return 0;
}

*/
