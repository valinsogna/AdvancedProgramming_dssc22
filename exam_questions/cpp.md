1. Name at least 5 variable types in c++

    In c++ there are built-in types know by the compiler, standard types for Standard C++ library (namespace std), derived Data types (include array, function, pointer, and reference) and custom types or user-defined types (enum, class/struct, typedef).

    Oss. long, short,signed,unsigned are modifiers.

    ```
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

2. What is "int overflow"?

    Overflow is a phenomenon where operations on 2 numbers exceeds the maximum (or goes below the minimum) value the data type can have in memory. Usually it is thought that integral  types are very large and people don't take into account the fact that sum of two numbers can be larger than the range. But in things like scientific and mathematical computation, this can happen. For example, an unhandled arithmetic overflow in the engine steering software was the primary cause of the crash of the maiden flight of the Ariane 5 rocket. 

    For c++, depending on the compiler and type system, usually int can range on 32-bits system $[-2^31, 2^31-1]$. 
    ```
    x = std::pow(-2,31) // 2^31 = 2147483648, include <cmath>
    x= x-1 //overflow.
    ```
    Include `<limits>` one can use function `std::numeric_limits<int>::min()/max()` to investigate the limits on his/her machine.
    Double has 2x more precision than float.
    Float is a 32-bit IEEE 754 single precision Floating Point Number – 1 bit for the sign, 8 bits for the exponent, and 23* for the value.    
    Float has 7 decimal digits of precision. double is a 64-bit IEEE 754 double precision Floating Point Number – 1 bit for the sign, 11 bits for the exponent, and 52* bits for the   value. double has 15 decimal digits of precision.

    Python instead has no limit on the size of the integer (but don't get happy about that, it's slow if you need a lot of those numbers).
    But floats do have limits: for double precision (which is used by default) you get and exponent (of 2) between -1022 and +1023 (-307 to 308 base 10) and ~16 decimal places.

3. Why `using namespace std` might not be a good idea?

    Name clashing btw imported libraries/namespaces.
    Alternative to this statement is to specify the namespace to which the identifier belongs using the scope operator(::) each time we declare a type. 
    Although the statement saves us from typing std:: whenever we wish to access a class or type defined in the std namespace, it imports the entirety of the std namespace into the    current namespace of the program. 
    - consider using typedefs: typedef std::cout cout_std;
    - import a single identifier. To import only std::cout we could use: using std::cout;

4. Which header do you have to include for the access to `std::cout`?

    `<iostream>` Tutte le funzioni e le classi sono dichiarate all'interno del namespace std.
    functions to handle the input and output stream in c++. This iostream header file contains various functions, including `std::cin`, `std::cout`, `std::endl`.

5. what would be the simplest "legal" program in c++?
    ```
    int main(){} // named global func as it's the entry point for the wrapper of the linker.
    ```
    
    Linker error is a complain about an "undefined reference to main": it means that the linker tried to create an executable and couldn't figure out where the main() function was located. This can happen if you forget to include the main function at all
    
    Signature:
    ```
    int main();
    int main(int argc, char *argv[]);
    ```

    Return 0 can be omitted. If your return 2, it compiles but in Linux/unix system if you exit with a status other than 0 then, then it print an error message to stderr.
    Via `echo $?` you can access the return type.
    Oss. `exit(1)` vs `return 1` -> return returns from the current function (like break) exit() terminates the whole program, wherever you call it from.

6. what is the difference in c++ between `struct` and `class`?

    If you don't specify public: or private:, members of a struct are public by default; members of a class are private by default
    struct are no C struct.

7. What does `break` statement do in a loop in c++? you can break out of the loop with `break` 
8. What does `continue` statement do in a loop? skip to the next iteration with `continue`

    ```
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
9. How do you define a static array of type int and size 7? R value or const, otherwise compiles but segmentation fault (run time error) (out of memory)
    ```
    int N{5};
    const int NN{5};
    int arr[5];
    int arr2[N];//THIS COMPILES, BUT IS VERY BAD, DON'T DO IT
    int arr3[NN];
    ```
10. What can you use to read interactive user input?

    From prompt:
    ```
    #include <iostream>
     ......

    int x{0};
    std::cin >> x;

    ```
    The `>>` is called "extraction operator".
    You can read more than one number if the user inputs them with spaces:
    ```
    int x{0},y{0};
    std::cin >> x >>y;
    ```
    To check types:
    ```
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

    ```
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

11. What is a reference?

    A reference variable is an alias, that is, another name for an already existing variable. Once a reference is initialized with a variable, either the variable name or the reference name may be used to refer to the variable.
    It's a pointer that is soon dereferenced.

    Differences between references and pointers:

    - You cannot have NULL references. 
    - You must always be able to assume that a reference is connected to a legitimate piece of storage.
    - Once a reference is initialized to an object, it cannot be changed to refer to another object. Pointers can be pointed to another object at any time. A reference cannot be re-bound or unbound, and it practically becomes just an alternative name for the object it is bound to

    A reference must be initialized when it is created. Pointers can be initialized at any time

12. What is a difference between passing variables to functions by reference and by value?
    copies

13. Why do we want to pass variables to functions by reference rather than by pointer?
    This is discouraged in C++ for "single variables" and can cause ambiguity and hard-to-catch bugs when you forget if it's an array or not, so avoid this unless you are using C-libraries. Arrays are already pointers and will always be passed "by pointer".

    ```
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
14. If the function accepts pointers (signature `int function(int* a)`), how do you pass a variable defined as `int x` to it?

    `int res = function(&x)` -> operatore di indirizzo

15. Why do we want to use `const` modifier whenever possible?

    `const` keyword specifies that a variable's value is constant and tells the compiler to prevent the programmer from modifying it.
    The const variable cannot be left un-initialized at the time of the assignment.
    It cannot be assigned value anywhere in the program.
    Explicit value needed to be provided to the constant variable at the time of declaration of the constant variable.

    - `const int *ptr_1 = &value;      // ptr_1 points to a “const int” value, so this is a pointer to a const value.`

    - `int *const ptr_2 = &value;        // ptr_2 points to an “int”, so this is a const pointer to a non-const value.`

    - `const int *const ptr_3 = &value;   // ptr_3 points to a “const int” value, so this is a const pointer to a const value.`

    Variables are passed to functions as const if we want to prevent them to be changed -> ex, print func 
    Also memeber func can be const if we promise not to modify any memeber variables: the object called by these functions cannot be modified.

16. If you have a pointer named `p`, how do you access a value it points to? What is the name of that process?
    A pointer is a variable that stores the memory address of whatever it points to. It needs to have a type to know how to read that memory.

    ```
    int a{0};
    int* pointer{nullptr}; //doesn't have to be initialized, but it's better to put `nullptr` when you create it.
    pointer=&a; //here & means *address of the variable*
    ```
    You can access it's element in 2 ways: via `operator[]` if it's an array or  **dereference** a pointer by placing a `*` before the name.
    ```
    std::cout<< *pointer << std::endl;
    ```

17. What value is stored in the pointer variable itself? address `0x7ffee67f66f8`

18. What can you say about a function that has signature `void function()`?

    A function is a block of code that performs some operation. It can take input parameters and it can return a value as output. If it doesn't return any value, it's return type is `void`. The simplest function you can write is:

    ```
    void function(){};
    ```

19. What is an `auto` keyword?

    If you are not sure which type the function returns or the return type is way too long, you use **auto** keyword.
    Auto ias deduced by compiler at compile time (statically typed language)

20. What is function overloading?
21. What is a recursive function?
22. What is the role of a constructor in a class?
23. How can we change private member variables of a class?
24. How do you create an object file with `g++`?
25. Why can't you just have eveything in one file?
26. What is the purpose of a "header guard"?
27. What does `-IFOLDER_NAME` mean when passed to `g++`?
28. Do tabs matter in a `Makefile`?
29. What does `$@` mean in a `Makefile`?
30. What does `$^` mean in a `Makefile`?
31. How to use `make` with a makefile that is not named `Makefile`?
32. What does it mean if a function is a friend of a class?
33. Why should non-class member operators be friends of classes?
34. Which header do you need to include to work with files?
35. How do you open a file in append mode?
36. how do you allocate a dynamic array in C++?
37. whats the difference between `delete` and `delete[]`?
38. when do you need to overload assignment operator for your class?
39. when do you need to create a copy constructor for your class?
40. when do you need to create a move constructor for your class?
41. what should you do if your class allocates resources, but you are sure you will never need a copy constructor?
42. what are protected class members?
43. what are virtual functions? 
44. what is an abstract class?
45. explain dynamic (runtime) polymorphism
46. why destructors should be made virtual?
47. what is this `[](){}()`?
48. what's the general structure of a lambda function?
49. what does "mutable" keyword do in a lambda function?

