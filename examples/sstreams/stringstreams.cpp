#include <string>
#include <sstream> //stingstreams
#include <iostream>

int main(){
    int a{90};
    std::ostringstream ss;
    ss<<a<<" + " <<a;
    //how to get the string from the stream
    std::string s=ss.str();
    std::cout<<s<<std::endl; //90 + 90
    
    std::istringstream ss2(s);
    
    int n; //will hold the number
 
    // Stream a number till white space is encountered
    ss2 >> n;
    char c;
    ss2>>c; //read the + sign
    char d; // only the first character of second 90 is read:9
    ss2>>d;
 
    // Print the number
    std::cout << n << " " << c << " " << d << std::endl; //90 + 9
}
