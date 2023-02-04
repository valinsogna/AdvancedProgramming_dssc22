#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

//this is a functor (before lambdas, this is how you define a function object)
//in fact, compiler will generate something like this for lambda functions
struct Hi{
    void operator()(){ // operator() takes no input and returns nothing
       std::cout<<"Hi!"<<std::endl; 
    }
};


int main(){
    Hi hi;
    //this is a functor, can call the variable as a function
    hi();
    
    std::vector<int> vec,vec2;
    vec.resize(10,0);
    vec2.resize(10,0);
    int count{0};
   
    //this all are valid expressions that do nothing
    [](){}; // a lambda func that doesn't capture anything and does nothing and it's not called
    []{}(); // a lambda func that doesn't capture anything and does nothing BUT it's called
    
    // This () is optional if you don't pass any arguments:
    // []{}() is the same as [](){}()
    []{}; // simpliest lambda, does nothing and is not called
    
    
    //actually, every lambda has it's own type, but you don't have to worry about that with auto
    auto addition = [](int x, int y)->double { return x + y; };
    
    //capture by reference
    int a{0};
    auto print_a = [&a]{std::cout<<a<<std::endl;};
    auto add_something = [&a](int s){ a=a+s;};
    a=1; 
    add_something(2);
    print_a(); //this will print 3
    
    //capture by value (copy): captures the value at the time of definition (not at the time of invocation)
    int b{0};
    auto print_b = [b]{std::cout<<b<<std::endl;};
    b=1; 
    //this will ignore the b change and still keep the zero
    print_b();
   
    auto very_useful_lambda = [a]() mutable {a=a+2;
        std::cout << "local a is: "<< a << std::endl; 
    };
    very_useful_lambda(); //this will print 5
    
    
    std::cout<<addition(3,5)<<std::endl; //this will print 8
    
    // Otherwise you can define and invoke lambda unnamed immediately:
    std::cout<<[](int x, int y) { return x + y; }(3,5)<<std::endl; //this will print 8
    
    //a totally nonsense example illustrating that you can invoke lambda immediately
    []{std::cout<<"meow"<<std::endl;}();
    
    
     //here are some useful functions from algorithm that use lambdas
    //unfortunately, you need an external variable for index
    // need to define and initialize count before
    std::generate(vec.begin(),vec.end(),[&count]{count++;return count*count;}); // I want to fill my vec with squares of integers
   // lamda is called for every elem in vec

    //sort wants a function that accepts two parameters and compares them
    std::sort(vec.begin(),vec.end(),[](int x,int y){return x>y;}); //sort in descending order: lambda is called for every pair of elements and returns a bool
  
    //for_each can be replaced by a range loop usually: vec INPUT, vec2 OUTPUT
    // It's up to user to check if vec2 is big enough
    std::for_each(vec.begin(),vec.end(),[](int i){std::cout<<i<<" ";});
    std::cout<<std::endl;
    
    //a useful function to do something with a vector and put it into another vector
    std::transform(vec.begin(),vec.end(),vec2.begin(),[](int& x){return x+2;});
    
    std::for_each(vec2.begin(),vec2.end(),[](int i){std::cout<<i<<" ";});
    std::cout<<std::endl;
    
    return 0;    
}
