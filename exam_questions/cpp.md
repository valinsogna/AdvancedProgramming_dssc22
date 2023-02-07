1. **Name at least 5 variable types in c++**

In c++ there are built-in types know by the compiler, standard types for Standard C++ library (namespace std), derived Datatypes (include array, function, pointer, and reference) and custom types or user-defined types (enum, class/struct,typedef).
Oss. long, short,signed,unsigned are modifiers.
```c++
bool var{true};
double x{3.5};
float  xx{3.5f};
int a{-1}; // on 32-bits system [-2^31, 2^31-1]
short int b{2};
long int c{3};
long long int d{4};
char s{'a'};
unsigned int g{6};
std::string name; //include the header <string>
void
nullptr
```
Oss. Var size:
    char/bool 1B
    int/float 4B
    double    8B
    ptr       8B (on 64-bits system)

2. **What is "int overflow"?**

Overflow is a phenomenon where operations on 2 numbers exceeds the maximum (or goes below the minimum) value the data type can have in memory. Usually it is thought that integral  types are very large and people don't take into account the fact that sum of two numbers can be larger than the range. But in things like scientific and mathematical computation, this can happen. For example, an unhandled arithmetic overflow in the engine steering software was the primary cause of the crash of the maiden flight of the Ariane 5 rocket. 

For c++, depending on the compiler and type system, usually int can range on 32-bits system $[-2^31, 2^31-1]$. 
```c++
x = std::pow(-2,31) // 2^31 = 2147483648, include <cmath>
x= x-1 //overflow.
```
Include `<limits>` one can use function `std::numeric_limits<int>::min()/max()` to investigate the limits on his/her machine.
Double has 2x more precision than float.
Float is a 32-bit IEEE 754 single precision Floating Point Number – 1 bit for the sign, 8 bits for the exponent, and 23* for the value.    
Float has 7 decimal digits of precision. double is a 64-bit IEEE 754 double precision Floating Point Number – 1 bit for the sign, 11 bits for the exponent, and 52* bits for the   value. double has 15 decimal digits of precision.

Python instead has no limit on the size of the integer (but don't get happy about that, it's slow if you need a lot ofthose numbers).
But floats do have limits: for double precision (which is used by default) you get and exponent (of 2) between -1022 and+1023 (-307 to 308 base 10) and ~16 decimal places.

3. **Why `using namespace std` might not be a good idea?**

Name clashing btw imported libraries/namespaces.
Alternative to this statement is to specify the namespace to which the identifier belongs using the scope operator(::) eachtime we declare a type. 
Although the statement saves us from typing std:: whenever we wish to access a class or type defined in the std namespace,it imports the entirety of the std namespace into the    current namespace of the program. 
- consider using typedefs: typedef std::cout cout_std;
- import a single identifier. To import only std::cout we could use: using std::cout;

4. **Which header do you have to include for the access to `std::cout`?**

`<iostream>` Tutte le funzioni e le classi sono dichiarate all'interno del namespace std.
functions to handle the input and output stream in c++. This iostream header file contains various functions, including `std::cin`, `std::cout`, `std::endl`.

5. **what would be the simplest "legal" program in c++?**
```c++
int main(){} // named global func as it's the entry point for the wrapper of the linker.
```
    
Linker error is a complain about an "undefined reference to main": it means that the linker tried to create an executableand couldn't figure out where the main() function was located. This can happen if you forget to include the main functionat all

Signature:
```c++
int main();
int main(int argc, char *argv[]);
```
Return 0 can be omitted. If your return 2, it compiles but in Linux/unix system if you exit with a status other than 0then, then it print an error message to stderr.
Via `echo $?` you can access the return type.
Oss. `exit(1)` vs `return 1` -> return returns from the current function (like break) exit() terminates the whole program,wherever you call it from.

6. **what is the difference in c++ between `struct` and `class`?**

If you don't specify public: or private:, members of a struct are public by default; members of a class are private by default
struct are no C struct.

7. **What does `break` statement do in a loop in c++?** you can break out of the loop with `break`
8. **What does `continue` statement do in a loop?** skip to the next iteration with `continue`

```c++
for (int i=0;i<7;i++){
    if(i>=3){break;}
    std::cout<< i <<" ";
}
std::cout<<std::endl;
//continue example
for (int i=0;i<7;i++){
    if(i==3){continue;}
    std::cout<< i <<" ";
}
```  
9. **How do you define a static array of type int and size 7?** 

R value or const, otherwise compiles but segmentation fault (run time error).
CSegfault is common condition that causes programs to crash; they are often associated with a file named core. Segfaults are caused by a program trying to read or write an illegal memory location

```c++
int N{5};
const int NN{5};
int arr[5];
int arr2[N];//THIS COMPILES, BUT IS VERY BAD, DON'T DO IT
int arr3[NN];
```
10. **What can you use to read interactive user input?**

From prompt:
```c++
#include <iostream>
int x{0};
std::cin >> x;
```
The `>>` is called "extraction operator".
You can read more than one number if the user inputs them with spaces:
```c++
int x{0},y{0};
std::cin >> x >>y;
```
To check types:
```c++
#include <sstream>
#include <iostream>

int main( int argc, char *argv[] ){
  std::istringstream ss(argv[1]);
  int x{0};
  //we try to read a number from the first passed argument
  if (!(ss >> x)) {
    std::cerr << "Invalid number: " << argv[1] << std::endl;
  } else if (!ss.eof()) {
    std::cerr << "There are trailing characters after the number: " << argv[1] << std::endl;
    std::cout<<"number was "<<x<<std::endl;
  }  

  return 0;
}
```
(the result will essentally be identical to calling `std::cin>>` twice)

```c++
#include <getopt.h>
int main(int argc, char * const argv[]) { 

    //c-style way to parse parameters
    //they should be passed like "-a 1 -b 9"
    int a{0}, b{0}, c{0}, d{0};
    int res{0};
    while( (res = getopt(argc, argv, "a:b:c:d:") ) != -1 ) {
        switch(res){
            case 'a':
                a = std::atoi(optarg);
                break;
            case 'b':
                b = std::atoi(optarg) ;
                break;
            case 'c':
                c = std::atoi(optarg) ;
                break;
            case 'd':
                d = std::atoi(optarg) ;
                break;
        }
    }
```

11. **What is a reference?**

A reference variable is an alias, that is, another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.
It's a pointer that is soon dereferenced.

Differences between references and pointers:

- You cannot have NULL references. 
- You must always be able to assume that a reference is connected to a legitimate piece of storage.
- Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time. A reference cannot be re-bound or unbound, and it practically becomes just an alternative name for the object it is bound to

A reference must be initialized when it is created. Pointers can be initialized at any time

12. **What is a difference between passing variables to functions by reference and by value?** copies

13. **Why do we want to pass variables to functions by reference rather than by pointer?**

This is discouraged in C++ for "single variables" and can cause ambiguity and hard-to-catch bugs when you forget if it's an array or not, so avoid this unless you are using C-libraries. Arrays are already pointers and will always be passed "by pointer".

```c++
void print_array(int* arr, const int N){
    //accessing "normally"
    for(int i=0;i<N;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
    //accessing with "pointer arythmetics"
    for(int i=0;i<N;i++){
        std::cout<<*(arr+i)<<" ";
    }
    std::cout<<std::endl;
}
int main(){
   const int N{5};
   int arr[N];//array is a pointer!!
   print_array(arr,N); 
}
```
14. **If the function accepts pointers (signature `int function(int* a)`), how do you pass a variable defined as `int x` to it?**

`int res = function(&x)` -> operatore di indirizzo

15. **Why do we want to use `const` modifier whenever possible?**

`const` keyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it.
The const variable cannot be left un-initialized at the time of the assignment.
It cannot be assigned value anywhere in the program.
Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.

- `const int *ptr_1 = &value;      // ptr_1 points to a “const int” value, so this is a pointer to a const value.`
- `int *const ptr_2 = &value;        // ptr_2 points to an “int”, so this is a const pointer to a non-const value.`
- `const int *const ptr_3 = &value;   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.`

Variables are passed to functions as const if we want to prevent them to be changed -> ex, print func 
Also memeber func can be const if we promise not to modify any memeber variables: the object called by these functions cannot be modified.

16. **If you have a pointer named `p`, how do you access a value it points to? What is the name of that process?**
A pointer is a variable that stores the memory address of whatever it points to. It needs to have a type to know how to read that memory.

```c++
int a{0};
int* pointer{nullptr}; //doesn't have to be initialized, but it's better to put `nullptr` when you create it.
pointer=&a; //here & means *address of the variable*
```
You can access it's element in 2 ways: via `operator[]` if it's an array or  **dereference** a pointer by placing a `*` before the name.
```c++
std::cout<< *pointer << std::endl;
```

17. **What value is stored in the pointer variable itself?** address `0x7ffee67f66f8`

18. **What can you say about a function that has signature `void function()`?**

A function is a block of code that performs some operation. It can take input parameters and it can return a value as output. If it doesn't return any value, it's return type is `void`. The simplest function you can write is:

```c++
void function(){};
```

19. **What is an `auto` keyword?**

If you are not sure which type the function returns or the return type is way too long, you use **auto** keyword.
Auto is deduced by compiler at compile time (statically typed language)

20. **What is function overloading?**

You can have different functions with the same name if they have a different number or a different type of the input parameters.

21. **What is a recursive function?**

Functions can call themselves: (from base case upwards)

```c++
unsigned long long int factorial(int N){
    if(N==1){
        return 1;
    }else{
        return N*factorial(N-1);
    }
}
```
Recursive functions are slower than iterations!

Benefits:
- it makes our code shorter and cleaner.
- Recursion is required in problems concerning data structures and advanced algorithms, such as Graph and Tree Traversal.

Disadvantages of C++ Recursion:

- It takes a lot of stack space compared to an iterative program.
- It uses more processor time.
- It can be more difficult to debug compared to an equivalent iterative program.

22. **What is the role of a constructor in a class?**

Special member functions that doesn't have a return type at all is *constructor*. Constructors exist to create an instance of the class and to initialize class member variables. Default constructor takes no parameters (if you don't want it to exist, you can use `CCoords() = delete;`).
Invoked automatically at the time of object creation. It is used to initialize the data members of new objects generally. The constructor in C++ has the same name as the class or structure. Constructor is invoked at the time of object creation. If no ctor is specified compilers makes it a default one.

```c++
class CCoords{
    double x;
    double y;
public:
    //default constructor
    CCoords(){
      x=0;y=0;  
    }
    //constructor with a parameter
    //a different syntax with the initializer list
    //it's "just a syntax" here, but can be important when member variable is also of some class type
    //pay attention to the initialization order!
    CCoords(double x1, double y1):x(x1),y(y1){
    }
};
```

23. **How can we change private member variables of a class?**

Externally we can't but friend and members func have acces to them so we can call set memebers functions to change them.

Inheritance (base -> derived) class:
- public -> public/protected remains.
- protected -> public/protected become protected.
- private -> public/protected become private.
Oss. private members of base class -> unaccessible to derived class.

24. **How do you create an object file with `g++`?** 

Machine code files generated by a compiler from source code.
The difference with an executable is that the object file isn't linked, so references to functions, symbols, etc aren't defined yet.

Compilation creates an object file:
`g++ -c -I -Wall -03 -std=c++14 file.cpp -o file.o` -> output: `file.o`

Linking:
`g++ -o file.x file.o`-> output: `file.x`

The option `-o` stands for "output" and lets you specify a name.

25. **Why can't you just have eveything in one file?**

Once you have more than two files in your program, writing all the compiling and linking lines by hand can become troublesome very fast. The `make` utility takes care of that for you. 

26. **What is the purpose of a "header guard"?**

To avoid multiple inclusions, we need `header guards`

```c++
#ifndef HELLO_F
#define HELLO_F
void hello();
#endif
```
or
```c++
#pragma once
void hello()
```

This `pragma` command is not in the language standard and only exists if compilers implemented it.

27. **What does `-IFOLDER_NAME` mean when passed to `g++`?**

The `-I.` here "includes the current directory". That means that the compiler will look in the current directory for the definition of the `hello()` function so that it could copy it to the `main.cpp`. If your headers are in a different folder (as they should be), specify that folder after the `I`. 

28. **Do tabs matter in a `Makefile`?** yes

```Makefile
# This is a comment line
CC=g++
# where to look for headers:
INCDIR=include
OBJDIR=obj
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -I$(INCDIR) -Wall -std=c++14
OBJECTS= main.o $(OBJDIR)/hello.o

hello.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp
obj/%.o: src/%.cpp  
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -rf *.o *.x 
```

It compares the modification time of the target file with the modification times of the dependency files. Any dependency file that has a more recent modification time than its target file forces the target file to be recreated. By default, the first target is the one that is built. Other targets are checked only if they are dependencies for the first target. For example, `clean` does not run when you just do `make` as `clean` is not a dependency of `hello.x`. For this case `make` and `make hello.x` are equivalent. You need to specify a target if it's not the first one -  if you type `make clean`, the object files and executables will be deleted. You can put bash scripts into targets

29. **What does `$@` mean in a `Makefile`?** target
30. **What does `$^` mean in a `Makefile`?** 

Evaluates to filenames of all the prerequisites, separated by spaces.
`$<` first dependency

There are two other usefull functions to use in Makefiles: 
- `wildcard` 
- `patsubst`. 
The first one just lists all the files with a given pattern (like all the `.cpp` files), the second one `$(patsubst PATTERN,REPLACEMENT,TEXT)` can substitute something is a pattern (it finds whitespace-separated words in TEXT that match PATTERN and replaces them with REPLACEMENT. Here PATTERN may contain a % which acts as a wildcard, matching any number of any characters within a word.). For example, to list all the program objects, you can do:

```Makefile
OBJECTS:=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
```

31. **How to use `make` with a makefile that is not named `Makefile`?**

You need to provide an input file to it called `Makefile` (this is the default name, if you want to change it, use `-f MyMakefileName` or `--file=MyMakefileName`, but generally keep the "Makefile" in the name to remember what that file is)


32. **What does it mean if a function is a friend of a class?**

What if you want to add an integer to your class variable? You need to define the operator out of the class rather than making it a class member function. Make it a `friend`, so that it could access private member variables

33. **Why should non-class member operators be friends of classes?** Keep only thing reguarding the class!

This really depends on whether a class is going to be on the left- or right-hand side of the call to operator== (or other operator like +). If a class is going to be on the right-hand side of the expression—and does not provide an implicit conversion to a type that can be compared with the left-hand side—you need to implement operator== as a separate function or as a friend of the class. If the operator needs to access private class data, it must be declared as a friend.

Otherwise get a habit to make it a friend in case you change to proper private values for a class with public members.
`friend std::ostream& operator<<(std::ostream& os, const CCoords& c);`

34. **Which header do you need to include to work with files?**

First, you need to include the header `<fstream>`

Then, you need to define variables use for accessing the files:
`std::ofstream` for output and `std::ifstream` for input.

```c++
//this will overwrite the file if it exists or create if it doesn't
std::ofstream filevar("test.txt");
//this will look for "test.txt" and fail if it doesn't exist
//but it won't crash, so better to check manually
std::ifstream filevar2("test.txt"); //assumes whitespaces and \n as separators
  if(filvar2){
    ...
  }  
```
After using the file, don't forget to `close()` it!

```c++
    filevar << "1 2 3"<<std::endl;
    filevar.close();
    int a{0},b{0},c{0};
    filevar2 >> a >>b >>c;
    std::cout<<a<< " " <<b <<" "<< c<<std::endl;
    filevar2.close();
```

35. **How do you open a file in append mode?**

If you don't want to overwrite an existing file, use:

```c++
filevar.open("test.txt", std::ios_base::app);
```

36. **how do you allocate a dynamic array in C++?**

On the Heap like C m/calloc, contiguos in memory.
kernel space 0xFFFFFFFF
stack
heap
global and static variables
executable code (all routines) 0x00000000

There is a substantial difference between declaring a normal array and allocating dynamic memory for a block of memory using `new`. 
The most important difference is that the size of a regular array needs to be a **constant expression**, and thus its size has to be determined at the moment of designing the program, before it is run, whereas the dynamic memory allocation performed by new allows to assign memory during runtime using any variable value as size.

The dynamic memory requested by our program is allocated by the system from the memory heap.

```c++
int* p =new int[N];
delete[] p;
```
Exception of type `bad_alloc` is thrown when the allocation fails

37. **whats the difference between `delete` and `delete[]`?** 1 or more var pointed
38. **when do you need to overload assignment operator for your class?** 

The copy assignment operator (operator=) is used to copy values from one object to another already existing object.

Class with raw and smart ptrs: compiler doesn't know how to make a "deep copy".
It copies only memebers (data) (shallow copy), it compiles but then crashes cause it calls twice.

```c++
template <typename T>
class MyClass{
public:
    size_t size;
    T* data;
    MyClass(const int& N);
    ~MyClass(); // don't need with unique_ptr
};

template<typename T> 
    MyClass<T>::MyClass(const int& N) {
    data=new T[N]; //data=std::make_unique<int[]>(N);
    size = N;
    for(int i=0;i<N;i++){
        data[i]=i;
    }
}

template<typename T> //don't need with unique_ptr
    MyClass<T>::~MyClass() {
    delete[] data;
    data=nullptr;
}
```

This might be enough as a "minimal survival", but what happens if you do

```c++
MyClass A(10),B(10);
A=B;
```
?

It will crash.
The compiler doesn't know how to make a "deep copy", you need to tell it:

```c++
template <typename T>
CMyClass<T>& CMyClass<T>::operator=(const CMyClass<T>& p){
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
//free memory of existing dynamic variables: don't need with unique_ptr
	if (data != nullptr){
		delete[] data;
		data=nullptr;
    }	
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;} //don't need with unique_ptr
	else{//don't need with unique_ptr
		data = new T[size]; //data.reset(new T[size]); per unique_ptrss
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else	
}//of cheking for self-assignement
return *this;
};
```

39. **when do you need to create a copy constructor for your class?** when you want to pass a class by value in a func!

Class with ptrs need copy ctor,assign and if raw also destructor.

```c++
// No need to free memory of existing dynamic variables
template<typename T> 
CMyClass<T>::CMyClass ( const CMyClass<T>& p ) { //don't modify p
    std::cout<<"copy constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
//create and copy dynamic variables
	if(p.data==nullptr){data=nullptr;} //don't need for unique_ptr
	else{ //don't need for unique_ptr
		data = new T[size]; // data.reset(new T[size]); for unique_ptr
		for(int i=0;i<size;i++){
			data[i]=p.data[i];
        };
	}//else
	
}//of cheking for self-assignement
    
}//copy constructor
```
Nel main:
```c++
CMyClass<int> obj(10);
CMyClass<int> obj(obj2);
func(obj);// copy ctor + dector
```

40. **when do you need to create a move constructor for your class?** steels resource to another and delete them

Sometimes you mihgt want to "move" your object instead of copying it (for example, if the object was temporary). There is `std::move` that does that for standard objects and can also do that for you if you create a move constructor and move assignment operator

```c++
template<typename T> 
CMyClass<T>::CMyClass ( CMyClass<T> && p ) { //modify p!!!!
     std::cout<<"move constructor called"<<std::endl;
//first check for self-assignment
if (this != &p) { 
//copy non-dynamic variables
	size=p.size;
    p.size=0;
//create and copy dynamic variables
    data=p.data; // data=std::move(p.data); for unique_ptr
    p.data=nullptr; // no need to delete for unique_ptr
}//of checking for self-assignment
    
}
}
```
In main:
```c++
CMyClass<int> obj(10);
CMyClass<int> obj3(10);
auto obj2=std::move(obj); //move constructor called
obj2=std::move(obj3); //move assignment operator called
``` 

41. **what should you do if your class allocates resources, but you are sure you will never need a copy constructor?**
A general rule is that, if you are having pointers in your class and need a destructor, you also need to overload assignment operator and the copy constructor. If you are sure that you will never use them, make them delete, otherwise you or someone else later might try to do unexpected things with your class and get a strange crash instead of a clear error message. So, do:

```c++
CMyClass& operator=(const CMyClass& p) = delete;
```

42. **what are protected class members?** like privates but derived can access them
43. **what are virtual functions?**

Instead of overloading the functions (happens at compile time), you can override them. This requires a `virtual` keyword.


A class that declares or inherits a virtual function is called a polymorphic class.

```c++
#include <iostream>

class Polygon {
  protected:
    int width, height;
  public:
    void set_values (int a, int b)
      { width=a; height=b; }
    virtual int area (){ 
        return 0; 
    }
 //  virtual int area ()=0;//makes the class abstract, then you can't have an object of it
    
};

class Rectangle: public Polygon {
  public:
      //override helps compiler and makes sure you don't type anything wrong
    int area() override{ 
        return width * height;
    }
};
```
44. **what is an abstract class?** 

`virtual int area ()=0;//makes the class abstract, then you can't have an object of it` at least one.
It's used for interface only purposes. Virtual functions must be overriden in derived classes, otherwise they become abstract too.

45. **explain dynamic (runtime) polymorphism** a pointer to virtual table func is added to your class VTB

a pointer to a derived class is type-compatible with a pointer to its base class. This is called runtime or dynamic polymorhism and is one of the key features of the object oriented design. (It's mostly not recommended in high performace applications, as it's slow.) VTF

46. **why destructors should be made virtual?**

Base -> (dctor)
Derived -> deals with memory (raw ptr) + dctor (delete)

=> Need to make virtual dctor of Base class! Otherwise memeory leak and dctor of Derived class is not called!
```c++
CDerived1<int>* c1 = new CDerived1<int>(12);
CBase1<int>* ptr=c1; //ONLY base dctor called, no derived dctor called, memory leak!!: if I add virtual both are called
delete ptr;
```

47. **what is this `[](){}()`?** This defines and calls a lamda function that takes no input, does nothing and can't even be called later as it has no name.
48. **what's the general structure of a lambda function?**

The general possible structure of a lambda function is 

```
[CAPTURES](PARAMETERS)->RETURN_TYPE{WHAT THE FUNCTION DOES}();
```

You can "capture" existing variables: get access to var defined in scope

 - [] 	Empty capture list, nothing will be captured.
 - [something] 	Capture `something` by copy.
 - [&something] 	Capture something by reference.
 - [x, &y] 	Capture y by-copy and y by-reference.
 - [=] 	Capture anything named from the enclosing scope by-copy.
 - [&] 	Capture anything named from the enclosing scope by-reference.
 - [&, x, y] 	Capture anything named from the enclosing scope by reference, except x and y which are captured by-copy.
 - [=, &x] 	Capture anything named from the enclosing scope by copy, except x which must be captured by-reference

Since we are using lambdas outside of STL, we probably need to give them names. The easiest way is let the compiler decide the type for you (it's actually different for each function)

```c++
auto func = [](int i){ return i; };
```

49. **what does "mutable" keyword do in a lambda function?**

The things captured by value are captured at the moment the lambda was created, not when it was called. Also, you can't change them by default. To do that, you need a keyword `mutable`

```c++
int a{0};
auto very_useful_lambda = [a]() mutable {a=a+2;
    std::cout << a << std::endl;
};
```

Now let's look at how to use them with algorithms:

```c++
int count{0};
//unfortunately, you need an external variable for index
std::generate(vec.begin(),vec.end(),[&count]{count++;return count*count;});
   
//sort wants a function that accepts two parameters and compares them
std::sort(vec.begin(),vec.end(),[](int x,int y){return x>y;});
  
//for_each can be replaced by a range loop usually
std::for_each(vec.begin(),vec.end(),[](int i){std::cout<<i<<std::endl;});


std::transform(vec.begin(),vec.end(),vec2.begin(),[](int& x){return x+2;});
```


-----------------------------------------------------------------------------------------------------------------------------------------
```c++
//using "this" is one of the ways to get around templated var in base class: 
std::cout<<this->field1<<" "<<this->field2<<" "<<std::endl; 
```

C fucntions `rand()` and `srand()` are also available, but use: `std::default_random_engine dre(seed);//engine`

### Various Topics: timing

You can use the `std::chrono` from the header `chrono`. The old c-style timing from `<ctime>` header also works, but is less accurate and less flexible for uses with modern interfaces, so we will not discuss any examples from it. To start the timings, do:

```c++
  std::chrono::time_point<std::chrono::steady_clock> t_start;
  t_start = std::chrono::steady_clock::now();//we could just use auto
```

To end:

```c++
auto t_end = std::chrono::steady_clock::now();
auto total = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t_start).count();
```

There are other clocks in `chrono`, for example `system_clock` and `high_resolution_clock`, but the first one depends on your laptop time and might give surprises if it changes during the execution (for example, corrected from time server) and the second one is implementation-dependent, so you never know what it really is.

Since we want to write c++, let's introduce the concept of "scoped timer" - the timer that calls it's desctructor when going out of scope and saves you from typing the time difference manually every time. The simplest example is in the file `simple_timer.cpp`

```c++
class CSimple_Timer{
  std::chrono::time_point<std::chrono::steady_clock> t_start;
  std::string time_what;
  void print_time(){
    auto t_end = std::chrono::steady_clock::now();
    auto total = std::chrono::duration_cast<std::chrono::milliseconds>(t_end - t_start).count();
    std::cout<<time_what<<" took " <<total<< " milliseconds"<<std::endl;
  }
public:
  CSimple_Timer(std::string s):
					 t_start{std::chrono::steady_clock::now()},
					 time_what{s} {}
  ~CSimple_Timer() { print_time();}
};
```

Here in the desctructor we print the time of what was executed while the timer object existed. This is also a nice example of a destrucor that doesn't just free memory, but actually does something else.

However, this timer is still not "good enough" if we want to measure the same things repeatedly. We need something that could keep track of different timer calls and print the result summary at the end. The solution for this is included in the `timer.cpp` file. 

 - **what's the main advantage of using templates?**

What if you want to write a function to print different types of data? You would need to overload your `print()` function for every type you are going to use it with. It becomes cumbersome very fast and makes code hard to maintain if new types are added. Luckily, in c++ there is an easy solution: templates.
The type needed will be deduced from the argument. If you want to have a different type from what the compiler would normally assume, you can specify that:

```c++
double a{3.9};
print<int>(a);
```

You can also have different templated arguments if you need. 

 - **why do people usually put definitions of templated functions directly into `.hpp` files?**

 Templates need to be "instantiated" by the compiler at compile time, thus if you separate the declarations and definitions into different files as is done in `C`, you have to instatiate it manually. In many cases, that almost defeats the purpose of using templates and, unless working with projects where you care for executable size, can be avoided by simply creating **"a header only library"**, that is, putting all the function/class definitions entirely into header files.

 - **except on types, what else can we template on?** interger numbers

 ```c++
template <typename T, short int N>
void add_number(T& var){
    var=var+N;
}

int main(){
    double b{4.7};
    add_number<double,7>(b);
    std::cout<<b<<std::endl;
    return 0;
}
```

 - **what is template specialization?**

 You can make the compiler produce very different functions based on the type. This is useful when dealing with old C-interface or when some operations are not permitted for certain types.

```c++
#include <typeinfo>

template <typename T>
void CMyClass<T>::Function(){
    if constexpr(std::is_same_v<int,T>){// compile time
        std::cout<<"we are dealing with int"<<std::endl;
    }
    if constexpr(std::is_same_v<double,T>){
        std::cout<<"we are dealing with double"<<std::endl;
    }
    if constexpr(std::is_integral_v<T>){
        std::cout<<"something \"integer\" "<<std::endl;
    }else{
        std::cout<<"something non \"integer\" "<<std::endl;
    }
}

```
 - **what is a variadic template?**

 You can template on a variable number of arguments, for example if you wanted to have a function that can be called as

```c++
myPrint(1,2,"Hi",9.0);
myPrint('c', 1.4, 9,0, "kjhkjhkjh");

```

First, you need to write a "normal" print function:

```c++
template <typename T>
void myPrint(const T& arg){
     std::cout<<arg<<" ";
}
```

Then, you use `...` (ellipsis) to tell the compiler that the number of variables can change:

```c++
template <typename T, typename... Types>
void myPrint(const T& arg, const Types&... args){
    std::cout<<arg<<" ";
    myPrint(args...);
}
```
You need the "normal" print function here to stop the recursion.

 - **why using `push_back` for `std::vector` is a bad idea?**

it's easy to lose perfomance if you don't know what you are doing. Specifically, there is a handy function `push_back`, which should be used with caution or outright avoided when speed matters.

What happens behind the scnenes is that the vector will reserve the memory for itself with what it believs as "enough", then allocate new elemement in that area. Once it runs out of reserved memory, it will *copy eveything to a new location*, which you obvioulsy want to avoid when working with anything big.

So, when working with vectors in hpc, try to treat them like arrays and awaid resizing more than once. Always use `resize(NUMBER)` function, then fill in the values normally. As an alternative, you can call `reserve(NUMBER)` and then do `push_back`, but this way it's not always clear when the vector decides it's time to "move", it's safer to stick with "resize()".
 - **how do you pass data from `std::vector` to a "C-style" function that needs a pointer?** either as `&myvec[0]` or `myvec.data()`.
 - **why you shouldn't use a "vector of vectors"?**
You want the data to be contiguous in memory, so never use something like  `std::vector<std::vector<int>>`. Use one-dimensional storage instead and access the `(i,j)` elements as `data[i*N+j]`.