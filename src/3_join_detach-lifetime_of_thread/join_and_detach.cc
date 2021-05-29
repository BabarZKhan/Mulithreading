//use of join(), detach() and joinable() in thread C++11


// JOIN NOTES
// 0. Once a thread is started we wait for this thread to finish by calling join() function on thread object
// 1. Double join will result into program termination.
// 2. If needed we should check thread is joinable before joining  (using joinable () function)


// DETACH NOTES
// 

/*
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

void run (int count) {
	while(count --> 0)
	cout << "Cppnuts" << endl;
	std::this_thread::sleep_for(chrono::seconds(3));
}

int main () {
	std::thread t1(run, 10);
	cout << "main ()" << endl;
	t1.join();
	cout << "main () after"<<endl;
	return 0;
}
*/


/*
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

void run (int count) {
	while(count --> 0)
	cout << count << " Cppnuts " << endl;
	std::this_thread::sleep_for(chrono::seconds(3));
	cout << "thread finished" << endl;
}

int main () {
	std::thread t1(run, 10);
	cout << "main ()" << endl;
	
	t1.detach();
	
	cout << "main () after"<<endl;
	return 0;
}
*/



#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

void run (int count) {
	while(count --> 0)
	cout << count << " Cppnuts " << endl;
	//std::this_thread::sleep_for(chrono::seconds(3));
	cout << "thread finished" << endl;
}

int main () {
	std::thread t1(run, 10);
	cout << "main ()" << endl;
	
	t1.detach();
	
	cout << "main () after"<<endl;
	//std::this_thread::sleep_for(chrono::seconds(5));
	return 0;
}
