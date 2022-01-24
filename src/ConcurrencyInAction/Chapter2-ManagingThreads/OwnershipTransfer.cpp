#include <iostream>
#include <thread>

using namespace std;

void f1() { cout << "f1()\n"; }
void f2() { cout << "f2()\n"; }


int main()
{
	// a new thread is started and associated with t1
	thread t1(f1);   // (A)

	// Ownership is then transferred over to t2 
	// and moves ownershipby when t2 is constructed
	thread t2 = move(t1);   // (B)

	// Now, t1 no longer has any associated thread of execution; 
	// the thread running f1 is now associated with t2.

	// A new thread is started and associated with a temporary thread object
	// The transfer of ownership into t1 doesn't require a call to move() to explicitly move ownership, 
	// because the owner is a temporary object-moving from temporaries is automatic and implicit.
	t1 = thread(f2);   // (C)

	// t3 is default constructed.
	// This means that it's created without any associated thread of execution.
	thread t3;   // (D)

	// Ownership of the thread currently associated with t2 is transferred into t3.
	// This time, with an explicit call to std::move(), because t2 is a named object. 
	// After all these moves, t1 is associated with the thread running f2, 
	// t2 has no associated thread, and t3 is associated with the thread running f1.
	t3 = move(t2);   // (E)

	// The final move transfers ownership of the thread running f1 back to t1 where it started. 
        // This assignment will terminate program!
	t1 = move(t3);   // (F)
                         // (G)
	return 0;
}