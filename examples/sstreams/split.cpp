#include <sstream>
#include <iostream>

int main( int argc, char *argv[] ){

  std::istringstream ss("1a2a3a4a5a6a7");
  std::string token;

  while(std::getline(ss, token, 'a')) { // use 'a' as separator and token is a string
    std::cout << token << " ";
  }
  std::cout<<std::endl;
  return 0;
}
