#include <iostream>
#include <memory>

template <typename T>
class CMyClass{
public:
    std::unique_ptr<T[]> data;
    size_t size;
    CMyClass(const int& N);
    void print();
    CMyClass& operator=(const CMyClass& p);
    CMyClass& operator=(CMyClass&& p);
    CMyClass operator+(const CMyClass& p);
    CMyClass(const CMyClass& p);
    CMyClass(CMyClass&& p);
    
};

template<typename T> 
    CMyClass<T>::CMyClass(const int& N) {
    //instead of new    
    data=std::make_unique<int[]>(N);
    size=N;
    for(int i=0;i<N;i++){
        data[i]=i;
    }
    std::cout<<"constructor called"<<std::endl;
}



template<typename T> 
void CMyClass<T>::print() {
     for(int i=0;i<size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;   
}


template <typename T>
CMyClass<T>& CMyClass<T>::operator=(const CMyClass<T>& p){
    std::cout<<"assignment operator called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
    data.reset(new T[size]);
    for(int i=0;i<size;i++){
        data[i]=p.data[i];
    }
}//of cheking for self-assignement
return *this;
};


template <typename T>
CMyClass<T>& CMyClass<T>::operator=(CMyClass<T>&& p){
    std::cout<<"move assignment operator called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
    p.size=0;
    data=std::move(p.data);
}//of checking for self-assignment
return *this;
};


template<typename T> 
CMyClass<T>::CMyClass ( const CMyClass<T>& p ) {
    std::cout<<"copy constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
//create and copy dynamic variables
	data.reset(new T[size]);
    for(int i=0;i<size;i++){
        data[i]=p.data[i];
    }
	
}//of cheking for self-assignement
    
}//copy constructor

template<typename T> 
CMyClass<T>::CMyClass ( CMyClass<T> && p ) {
     std::cout<<"move constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
    p.size=0;
//create and copy dynamic variables
    data=std::move(p.data);
}//of checking for self-assignment
    
}



//nonsense function to see what happens 
template <typename T>
void a_function(CMyClass<T> obj){
    std::cout<<obj.size<<std::endl;
}


template<typename T> 
CMyClass<T> CMyClass<T>::operator+ ( const CMyClass<T>& p ) {
    std::cout<<"plus operator called"<<std::endl;
    if (size!=p.size){std::cerr<<"not working with different sizes"<<std::endl;
        exit(1);
    }
    CMyClass<T> result(size);
    for(int i=0;i<size;i++){
        result.data[i]=data[i]+p.data[i];
    }    
    return result;
}


int main(){
   
    CMyClass<int> obj(10);
    CMyClass<int> obj2(10);
   //THIS ACTUALLY NEVER CALLS ASSIGNMENT OPERATOR! 
   auto obj3=obj2+obj;
    obj2.print();
    
    //will crash without a copy constructor
    a_function(obj);
    //another use of copy constructor
    CMyClass<int> obj4(obj3);
    
    //obj3 still exists, but assume it can't be used anymore 
    auto obj5=std::move(obj); 
    
    obj5=std::move(obj2);
    obj5.print();
    return 0;
}
 
 
 
