#include <iostream>
//look at this file until you understand everything
//it's very important


void add_two(int& a){
    std::cout<<"function with reference was called" <<std::endl;
    a=a+2;
}

void add_two(int* a){
    std::cout<<"function with pointer was called" <<std::endl;
    *a=*a+2;
}



int main(){
    int a{77};
    //initialization of reference is obligatory
    int& c{a};//c becomes an alias for a: if a changes, c changes and viceversa
    
    //initialization of pointer is not obligatory, but done "to be safe" 
    //it is NULL in c, don't use NULL in c++
    int* b{nullptr};
    b=&a;
    
    std::cout<<"a is: "<<a<<std::endl;
    std::cout<<"c is: "<<c<<std::endl;
    std::cout<<"address of a is: "<<&a<<std::endl; //0x7ffee67f66f8
    std::cout<<"address of c is: "<<&c<<std::endl; //same as adress of a: 0x7ffee67f66f8
    
    //let's change a:
    a=a+2;
    std::cout<<"a is: "<<a<<std::endl;  //79
    std::cout<<"c is: "<<c<<std::endl;  //79 changed too!
        
    //let's change c:
    c=c+2;
    std::cout<<"a is: "<<a<<std::endl;  //81 too!
    std::cout<<"c is: "<<c<<std::endl;  //81
    
    //what is b
    std::cout<<"b is: "<<b<<std::endl; //0x7ffee67f66f8
    std::cout<<"b points to value "<<*b<<std::endl; //81 latest value of a
    
    //let's change a with b
    *b=a+2;
    
    std::cout<<"a is: "<<a<<std::endl;  //83: changed!
    
    //let's test functions:
    add_two(a);
    std::cout<<"a is: "<<a<<std::endl;  //85
    add_two(c);
    std::cout<<"a is: "<<a<<std::endl;  //87 alias
    add_two(&a);//pointer func is called
    std::cout<<"a is: "<<a<<std::endl;  //89
    add_two(b);//pointer func is called
    std::cout<<"a is: "<<a<<std::endl;  //91
      
    return 0;
}
