#include <iostream>

template <typename T>
class MyClass{
public:
    T* data;
    MyClass(){};
    MyClass(const int& N);
    ~MyClass(); // must be defined since we need to free the memory allocated by new, after the object is destroyed
};

template<typename T> 
    MyClass<T>::MyClass(const int& N) {
    data=new T[N];
    for(int i=0;i<N;i++){
        data[i]=i;
    }    
}


template<typename T> 
    MyClass<T>::~MyClass() {
    delete[] data;
    data=nullptr; // dangling pointer: a pointer that points to a memory location that has been freed
    std::cout<<"destructor called"<<std::endl;
}



int main(){
   int N{12};
    int* p =new int[N];
    for(int i=0;i<N;i++){
        p[i]=i;
        std::cout<<p[i]<<" ";
    }
    std::cout<<std::endl;
    delete[] p; 
    
    MyClass<int> obj(10);
    
    
    return 0;
}
