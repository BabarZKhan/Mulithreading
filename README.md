# C++ Mulithreading 

 - (1)   -  Threads in C++
 - (2)   -  Different Types to create threads
 - (3)   -  Join and Detach with Joinable Threading 
 - (4)   -  Mutex in C++ threading 
 - (5)   -  Mutext try lock 
 - (6)   -  std_try_lock in C++ threading 
 - (7)   -  Time Mutex in C++ threading 
 - (8)   -  Recursive mutex in C++ threading 
 - (9)   -  Lock guard
 - (10)  -  Unique Lock 
 - (11)  -  Condition Variable in C++ threading 
 - (12)  -  Deadlock 
 - (13)  -  Thread or Process Synchronization 
 - (14)  -  std_lock
 - (15)  -  std_future and std_promise in C++ threading
 - (16)  -  std_async
 - (17)  -  producer and consumer
 - (18)  -  sleep vs wait in threading 
 
 
 

 

# Threads vs Tasks
| Criteria           |  Thread    |  Tasks |
| -------------------------- | ------------- |----------------------------------- | 
|     Header                       |       ``` <thread> ```                             |     ``` <future>```                              |             
|     Participants                 |       creator and child thread                     |     promise and future                           |         
|     Communication                |       shared variable                              |    communication channel                         |   
|     Thread creation              |       obligatory                                   |    optional                                      |    
|     Synchronization              |       join() call waits                            |    get() call blocks                             |       
|     Exception in child thread    |       child and creator threat terminates          |    returns value of the get() call               |     
|     Kinds of communication       |       values                                       |    values, notifications and exceptions          |         


# Threads vs Tasks Summary:
 - Threads: Create using  ``` std::thread ```
    - Does not return a value 
 
 - Tasks: Create using ``` std:async``` 
     - Returns a value

-  Both can use:
   - Pointer to function
   - Functor
   - Lambda functions
