#include <iostream>
#include <cmath>
#include <memory> //for std::unique_ptr


class CMyException: public std::exception{ //inherit from std::exception
  const char* what() const noexcept override{ // it's a virtual func in exception
    return "My exception happened";
  }
};

int main(){
// throw 999; //if you don't catch it'll call std::terminate   
  try{
    throw 777;
  }
  catch (int excep){
    std::cout << "Caught Exception  " << excep << '\n';
  }
    
  try{
    throw CMyException();  // ctor of CMyException is called  
        
   }catch (std::exception& e){ 
    std::cout << e.what() << std::endl; // call what() of CMyException (DErived class)
  // output: My exception happened
  }
  
  try
  {
    double* myarray= new double[10000000000000000];
  }
  catch (std::exception& e)
  {
    std::cout << "Standard exception: " << e.what() << std::endl;
    // output: Standard exception: bad_alloc
  }

  return 0;
    
}
