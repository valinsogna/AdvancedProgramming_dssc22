#include <iostream>

class Shape{
 public:
  virtual void print()=0;
  virtual ~Shape(){};
};

class Circle: public Shape{
  double r=0;
  void print() override { std::cout << r << std::endl; }

  public:
  void print2() { print(); }
};

int main(){
  Circle c; 
  //c.print(); can't do this, because print is private
  c.print2();
  //But if I create a ptr I can use Dynamic Polymorphism and access the print function of the derived class:
  Shape* s = &c;
  s->print();
}