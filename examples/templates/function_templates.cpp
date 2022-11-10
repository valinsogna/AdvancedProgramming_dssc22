#include <iostream>

template <typename T>
void print(const T& x){
    //all we need is the operator << be defined for the type T
    std::cout<<x<<std::endl;
}

//As return type
template <typename T>
T sum(const T& a, const T& b){
    return a+b;
}


template <typename T1, typename T2>
void weird_function(T1& a, T2& b){
    a=a+1;
    b=b-1;
}


int main(){
    int a{8};
    double b{9.7};
    print(a);
    print(b);
    //we can force a choice if we want
    print<int>(b); //this will print 9
    //here if you don't specify "double" compiler will complain cause it can't decide
    auto c=sum<double>(a,b); 
    print(c);//this will print 17.7
    weird_function(a,b);
    print(a);   //this will print 9
    print(b); //this will print 8.7
    return 0;
}
