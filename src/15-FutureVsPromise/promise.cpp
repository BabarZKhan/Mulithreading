// promiseFuture.cpp

#include <chrono>
#include <condition_variable>
#include <future>
#include <iostream>
#include <thread>
#include <utility>

using namespace std::chrono;

void product(std::promise<int>&& intPromise, int a, int b)
{
    intPromise.set_value(a * b);
}

struct Div {

    void operator()(std::promise<int>&& intPromise, int a, int b) const
    {
        intPromise.set_value(a / b);
    }
};

int main()
{

    int a = 20;
    int b = 10;

    std::cout << std::endl;

    // define the promises
    std::promise<int> prodPromise;
    std::promise<int> divPromise;

    //**************************************************************************
    // First get the futures
    std::chrono::time_point<std::chrono::system_clock> start_1, end_1;
    start_1 = std::chrono::system_clock::now();
    std::future<int> prodResult = prodPromise.get_future();
    end_1 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_1 = end_1 - start_1;
    std::time_t end_time_1 = std::chrono::system_clock::to_time_t(end_1);

    std::cout << "finished computation at " << std::ctime(&end_time_1)
              << "elapsed time: " << elapsed_seconds_1.count() << "s\n";
    //****************************************************************************

    //****************************************************************************
    std::chrono::time_point<std::chrono::system_clock> start_2, end_2;
    start_2 = std::chrono::system_clock::now();
    // calculate the result in a separate thread
    std::thread prodThread(product, std::move(prodPromise), a, b);

    end_2 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_2 = end_2 - start_2;
    std::time_t end_time_2 = std::chrono::system_clock::to_time_t(end_2);

    std::cout << "finished computation at " << std::ctime(&end_time_2)
              << "elapsed time: " << elapsed_seconds_2.count() << "s\n";
    //****************************************************************************

    //*******************************************************************************
    std::chrono::time_point<std::chrono::system_clock> start_3, end_3;
    start_3 = std::chrono::system_clock::now();
    std::future<int> divResult = divPromise.get_future();
    end_3 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_3 = end_3 - start_3;
    std::time_t end_time_3 = std::chrono::system_clock::to_time_t(end_3);

    std::cout << "finished computation at " << std::ctime(&end_time_3)
              << "elapsed time: " << elapsed_seconds_3.count() << "s\n";

    //******************************************************************************

    //**********************************************************************************
    Div div;

    std::chrono::time_point<std::chrono::system_clock> start_4, end_4;
    start_4 = std::chrono::system_clock::now();
    std::thread divThread(div, std::move(divPromise), a, b);
    end_4 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_4 = end_4 - start_4;
    std::time_t end_time_4 = std::chrono::system_clock::to_time_t(end_4);

    std::cout << "finished computation at " << std::ctime(&end_time_4)
              << "elapsed time: " << elapsed_seconds_4.count() << "s\n";
    //************************************************************************************

    // get the result
    //***********************************************************************************

    std::chrono::time_point<std::chrono::system_clock> start_5, end_5;
    start_5 = std::chrono::system_clock::now();
    std::cout << "20*10= " << prodResult.get() << std::endl;

    end_5 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_5 = end_5 - start_5;
    std::time_t end_time_5 = std::chrono::system_clock::to_time_t(end_5);

    std::cout << "finished computation at " << std::ctime(&end_time_5)
              << "elapsed time: " << elapsed_seconds_5.count() << "s\n";
    //**********************************************************************************+

    //*****************************************************************************
    std::chrono::time_point<std::chrono::system_clock> start_6, end_6;
    start_6 = std::chrono::system_clock::now();

    std::cout << "20/10= " << divResult.get() << std::endl;

    end_6 = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds_6 = end_6 - start_6;
    std::time_t end_time_6 = std::chrono::system_clock::to_time_t(end_6);

    std::cout << "finished computation at " << std::ctime(&end_time_6)
              << "elapsed time: " << elapsed_seconds_6.count() << "s\n";
    //**********************************************************************************

    prodThread.join();
    divThread.join();

    std::cout << std::endl;
}
