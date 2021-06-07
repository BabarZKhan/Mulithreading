// async.cpp




//std:.async feels like an asynchronous function call. Under the hood std::async is a task. One, which is extremely easy to use
#include <future>
#include <iostream>
#include <string>

std::string fooFunction(const std::string& s){
  return "foo ninja " + s + ".";
}

class FooFunctionObject{
  public:
    std::string operator()(const std::string& s) const {
      return "foo ninja " + s + ".";
    }
};

int main(){

  std::cout << std::endl;

  // future with function
  auto futureFunction= std::async(fooFunction,"function");

  // future with function object
  FooFunctionObject fooFunctionObject;
  auto futureFunctionObject= std::async(fooFunctionObject,"function object");

  // future with lambda function
  auto futureLambda= std::async([](const std::string& s ){return "Hello C++11 from " + s + ".";},"lambda function");

  std::cout << futureFunction.get() << "\n" 
	    << futureFunctionObject.get() << "\n" 
	    << futureLambda.get() << std::endl;

  std::cout << std::endl;

}

