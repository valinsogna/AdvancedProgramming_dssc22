#include <iostream>
#include <typeinfo>

/*
t is possible in C++ to get a special behavior for a particular data type. This is called template specialization
*/

template <typename T>
class CMyClass{
public:    
    void Function();
    
};

// if constexpr: condition evaluated at compile time
template <typename T>
void CMyClass<T>::Function(){
    if constexpr(std::is_same_v<int,T>){ // use -std=c++17
        std::cout<<"we are dealing with int"<<std::endl;
    }
    if constexpr(std::is_same_v<double,T>){
        std::cout<<"we are dealing with double"<<std::endl;
    }
    if constexpr(std::is_integral_v<T>){
        std::cout<<"something \"integer\" "<<std::endl;
    }else{
        std::cout<<"something non \"integer\" "<<std::endl;
    }
}

int main(){
    CMyClass<long long> var;
    var.Function();
    
}
