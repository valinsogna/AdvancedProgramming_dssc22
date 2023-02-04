#include <iostream>

class Shape{
 public:
  virtual void print(){};
  ~Shape(){};
};

class Polygon: public Shape{
  double* v;
  void print() override {std::cout<<"hi"<<std::endl;};
  public:
  Polygon(const int&N){v=new double[N];}; //must be public
  ~Polygon(){delete[] v;};
};

int main(){
  Shape* s = new Polygon(7);
  s->print(); // s is a ptr: calls the print of DERIVED class
}