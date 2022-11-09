#include <iostream>

//simple function example
//it's just a syntax example, it's not optimal at all
int add_two(int a){ //works but not good
    return a+2;
}

//this will not change a
void add_two_wrong(int a){
    a=a+2;
}

//this will change a
void add_two_ref(int& a){
    a=a+2;
}

//same example as the first, but optimal
//renamed to avoid ambiguity
int add_two_best(const int& a){
    return a+2;
}

//this will change a and b
//can overload the function because the number of variables is different
void add_two_ref(int&a, int&b){
    a=a+2;
    b=b+2;
}

//this will change a and b
//can overload the function because the type of variable is different
void add_two_ref(double& a){
    a=a+2;
}

//now let's look at c-style (don't use it unless interfacing with c libraries)
//this will change a
void add_two_p(int* a){
    *a=*a+2;
}


int main(){
    
    int a{2};
    //"auto" keyword is very useful when you don't remember the type of the function
    //or when it is complicated
    auto b=add_two(a);
    std::cout<<" a is "<<a<<std::endl;  //a is 2
    std::cout<<" b is "<<b<<std::endl;  //b is 4
    add_two_wrong(a);
    std::cout<<"after calling a wrong function a is "<<a<<std::endl;   //a is still 2
    add_two_ref(a);
    std::cout<<"after calling a correct function a is "<<a<<std::endl; //a is 4
    //c-style
    add_two_p(&a);  //a is 6 but it's not recommended
    std::cout<<"after calling a c-style function a is "<<a<<std::endl;
   return 0;
}
