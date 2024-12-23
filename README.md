<a href="https://github.com/mortennobel/cpp-cheatsheet"><img align="right" src="https://camo.githubusercontent.com/38ef81f8aca64bb9a64448d0d70f1308ef5341ab/68747470733a2f2f73332e616d617a6f6e6177732e636f6d2f6769746875622f726962626f6e732f666f726b6d655f72696768745f6461726b626c75655f3132313632312e706e67" alt="Fork me on GitHub" data-canonical-src="https://s3.amazonaws.com/github/ribbons/forkme_right_darkblue_121621.png"></a>


![concurrency](https://user-images.githubusercontent.com/46613555/160706055-44c1f034-e9d5-46a2-b6d0-9ce28b2da9d9.JPG)




# C++ Multithreading
Everything you wanted to know about C++ multithreading but were too afraid to........ 
In this repo I will be pushing my example codes that I have developed while learning multi-threading in C++ 11, C++ 14, C++ 17 and C++ 20. 

Natural order of topics in C++ Multithreading (Roadmap)
-------------------------------------------------------
This natural order (roadmap) is from the TOC of the book [1]. 
 - Topic 1: Hello, world of concurrency in C++!
 - Topic 2: Managing Threads
 - Topic 3: Sharing data between Threads
 - Topic 4: Synchronizing concurrent operations
 - Topic 5: The C++ memory model and operations on atomic types
 - Topic 6: Designing lock-based concurrent data structures
 - Topic 7: Designing lock-free concurrent data structures
 - Topic 8: Designing concurrent code
 - Topic 9: Advanced thread management



Further breakdown of Roadmap: 
----------------------------

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
 - (16)  -  std_async_(create_a_task)
 - (17)  -  producer and consumer
 - (18)  -  sleep vs wait in threading 
 
 
 

 

Threads vs Tasks:
----------------
| Criteria           |  Thread    |  Tasks |
| -------------------------- | ------------- |----------------------------------- | 
|     Header                       |       ``` <thread> ```                             |     ``` <future>```                              |             
|     Participants                 |       creator and child thread                     |     promise and future                           |         
|     Communication                |       shared variable                              |    communication channel                         |   
|     Thread creation              |       obligatory                                   |    optional                                      |    
|     Synchronization              |       join() call waits                            |    get() call blocks                             |       
|     Exception in child thread    |       child and creator threat terminates          |    returns value of the get() call               |     
|     Kinds of communication       |       values                                       |    values, notifications and exceptions          |         


Threads vs Tasks Summary:
------------------------

- Threads: Create using  ``` std::thread ```
    - Does not return a value 
 
 - Tasks: Create using ``` std:async``` 
     - Returns a value

-  Both can use:
   - Pointer to function
   - Functor
   - Lambda functions
   
Contributing:
-------------

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are greatly appreciated. Following are the steps to contribute:

- Fork the Project
- Create your Feature Branch (git checkout -b feature/AmazingFeature)
- Commit your Changes (git commit -m 'Add some AmazingFeature')
- Push to the Branch (git push origin feature/AmazingFeature)
- Open a Pull Request
   
   
References:
-----------

   - [1] Book called *C++ Concurrency in action* Practical Multithreading by Anthony Williams 
   - [2] Blog [Modernescpp](https://www.modernescpp.com/) and its [examples](https://github.com/RainerGrimm/ModernesCppSource)
   - [3] [An Introduction to Parallel Computing in C++](https://www.cs.cmu.edu/~15210/pasl.html)
