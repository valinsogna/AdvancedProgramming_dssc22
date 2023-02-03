#include <iostream>
#include <memory>


void function(int* p){
    std::cout<<p<<std::endl;
}

int main(){
    //one problem less, we don't need to delete anymore!
    std::unique_ptr<int[]> p(new int[5]);    //use int[]: otherwise does not provide a subscript operator p[i]
    // or use std::make_unique<int[]>(5);
    for(int i=0;i<5;i++){
        p[i]=i;
        std::cout<<p[i]<<" ";
    }
    //how to pass to a C-style function: raw pointer
    function(p.get()); // function must not deallocate the pointer
    
    
    
    return 0;
}
