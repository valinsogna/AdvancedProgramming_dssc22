#include <iostream>

class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
};

class Circle: public Shape{
  double r;
  void print() override { std::cout << r << std::endl; }

  public:
  void print2() { print(); }
};

int main(){
  Circle c; 
  //c.print(); can't do this, because print is private
  c.print2();
}