1. **How do you create markdown cell in Jupyter? (with keyboard commands)** press `esc` (to get into command mode) , then `m` 

2. **How do you delete a cell in Jupyter (with keyboard command)?** type `esc`, then`dd`

3. **How do you add a cell above the current one in Jupyter (with keyboard command)?** a cell above the current one, press `esc`, then `a`

4. **What advantage does conda environment provide over a system-wide installation of python?**

creates virtual env so 1) install packages in different paths without messing with your system 2) gives reproducibility of packages

5. **What does it mean that variables are dynamically typed in python?** vs statically typed (C++)

var are labels on objects (like boxes) so var can refere toother types
where the interpreter assigns variables a type at runtime based on the variable's value at the time.
type checking is performed at runtime. For example, Python is a dynamically typed language. It means that the type of a variable is allowed to change over its lifetime.

6. **What's the difference between python and C/C++ integers?** overflow

There is no limit on the size of the integer (but don't get happy about that, it's slow if you need a lot of those numbers).
floats do have limits: for double precision (which is used by default) you get and exponent (of 2) between -1022 and +1023 (-307 to 308 base 10) and ~16 decimal places.

7. **Explain the difference between lists, sets and tuples in python.** containers

Lists is Mutable	Set is Mutable	Tuple is Immutable
It is Ordered collection of items	It is Unordered collection of items	It is Ordered collection of items
Items in list can be replaced or changed	Items in set cannot be changed or replaced	Items in tuple cannot be changed or replaced.

OSS. mutable .i.e it can be converted into another data type and can store any data element in it.
Oss. immutable wrt id (no new box can be created). each different obj has a unique id. -> l.append() doesn't modify id.

- The list is a datatype available in Python which can be written as a list of comma-separated values (items) between square brackets.
- List are mutable .i.e it can be converted into another data type and can store any data element in it.
- List can store any type of element.
- resizable
- iterable


- Tuple is an immutable sequence in python.
- It cannot be changed or replaced since it is immutable.
- It is defined under parenthesis().
- Tuples can store any type of element.
- iterable
- 6 times faster than lists.

Sets: kind of dictionaries with only keys (immutable).
iterable, mutable, and has no duplicate elements. The major advantage of using a set, as opposed to a list, is that it has a highly optimized method for checking whether a specific element is contained in the set.
Sets are an unordered collection of elements or unintended collection of items In python.
Here the order in which the elements are added into the set is not fixed, it can change frequently.
It is defined under curly braces{}
Sets are mutable, however, only immutable objects can be stored in it.
can't s={} but s=set() 

8. **What does negative index mean when accessing list elements?** from last -1

9. How do you print the first N elements of a list? `print(lr[:N])`

10. How do you print every Nth element of a list? `print(lr[::N])`

11. How do you print the reverse list? `print(lr[::-1])`

12. Give an example of a list comprehension. 
`print( [x if not x%2 else -x for x in range(10)]` 
`[`'object to go in list' `for` 'input' `in` 'list/generator' `if` 'condition'  `]`

13. Give an example of cell and line magic commands in Jupyter. %lsmagic
```python
%timeit l = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
%timeit t = (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)
```

14. Write a "hello world" function in python (syntax errors are not ok in hello world even on paper).
```python
def hello(name):
    """prints 'hello' followed by the arg name"""
    print("hello,", name)


hello("cat")
hello(name="cat")
```

15. What are keyword function arguments in python and what is their advantage?

A keyword argument is an argument passed to a function or method which is preceded by a keyword and an equals sign. The general form is: 

```
function(keyword=value)
```
This way you don't have to remember the order of the arguments.

16. Why shouldn't you do `from numpy import *`?

**never do `from numpy inport *`**

**never do `%pylab inline`**: import matplotlib and numpy

This can only be done when you really need to save screen space and typing time (like is done in your other lectures, but never in real life. Remember `using namespace std`? This is even worse.

17. **What is the advantage of using numpy arrays over lists? What are the dangers?** overflow (also int) but fast

```python
A=np.array(range(0,900)).reshape(30,30)
B=np.array(range(34,934)).reshape(30,30)
% timeit np.matmul(A,B)
```
```python
A=[[x for x in range(30)] for i in range(30)]
B=[[x+34 for x in range(30)] for i in range(30)]
%timeit np.matmul(A,B)
```
10 times faster

18. **What's the most widely used package for plotting in python?** matplotlib.pyplot or seaborn

```python
from matplotlib import pyplot as plt
x = np.linspace(0,10,100)
y = np.sin(x)
plt.plot(x,y)
```

19. **What's the purpose of `__str__` method in a python class?** "overload" print func

```python
class MyThirdClass:
    def __init__(self,a,b):
        self.a=a
        self.b=b
        
    def print(self): #non pythonic way, avoid it
        print(a,b)
        
    def __add__(self,other):   
        a=self.a+other.a
        b=self.b+other.b
        return MyThirdClass(a,b)
        
    def __str__(self):
        return "{0},{1}".format(self.a, self.b) #"converts" class to a string
```

20. What package can you use in python for symbolic calculations?

```python
import sympy as sp
x, y = sp.symbols('x y')
h = sp.symbols('h')
sp.sin(x).series(x, x0=h, n=5)
```

21. What are decorators? Write an example (minor syntax errors are ok here)

```python
# importing libraries
import time
import math
 
# decorator to calculate duration
# taken by any function.
def calculate_time(func):
     
    # added arguments inside the inner1,
    # if function takes any arguments,
    # can be added like this.
    def inner1(*args, **kwargs):
 
        # storing time before function execution
        begin = time.time()
         
        func(*args, **kwargs)
 
        # storing time after function execution
        end = time.time()
        print("Total time taken in : ", func.__name__, end - begin)
 
return inner1
 
# this can be added to any function present,
# in this case to calculate a factorial
@calculate_time
def factorial(num):
 
    # sleep 2 seconds because it takes very less time
    # so that you can see the actual difference
    time.sleep(2)
    print(math.factorial(num))
 
# calling the function.
factorial(10)
```

22. **Name two ways of calling c++ code from python.**

**Cython** is a package used to speed up Python code by compiling it with **C**.
**Pybind11** is an header-only library (no need to compile it) used to use to import C++ code in Python and viceversa.
**Ctypes** is a package and it's better for pure C than for C++ overwise you need to write too many wrappers.
Even if wrapping C++ classes might be a huge pain, you can still just call the whole program in `external C` `no_main()` and hide all the templates and classes inside that.

First, you need to create a `C` shared library.

```g++ -fPIC -shared -o libhellotest.so hello.cpp```

where `hello.cpp` constains some functions, for example:

```cpp
#include <iostream>
extern "C" {
    void hello(){
        std::cout<<"Hello, World!"<<std::endl;
    }
}
```

We can't really use "real C++" inside the `extern C`, so no classes, no templates, only functions.
The compiler flags `-fPIC -shared` are needed to create the library object (you have seen it with `pybind` already)

```python
libObject = ctypes.CDLL('./libhellotest.so')
libObject.hello()
```

23. **What is pandas? Name at least 5 functions from that package.**

Pandas is an Python package that is widely used for data data analysis and machine learning.
First data type we will try to use is one dimensional arrays ("columns") called `Series`:

```python
mylist = [2, 8, 99,1]# or from dict you can specifiy index (usually starts from 0)
myvar = pd.Series(mylist)
```

To work with tables rather than vectors, we need to use `DataFrame`:
```python
mydataset = {
  'cats': ["grey", "black", "white"],
  'age': [3, 7, 2]
}
myvar = pd.DataFrame(mydataset)
myvar.loc[2] #to access rows
df = pd.read_csv('example.csv') #load files as dataframe
print(df.head())
print(df.tail())
print(df.info())#nan num of cols etc
df.dropna(inplace = True) #deletes directly (you might not have space otherwise)
df.groupby('cats')['age'].mean()
```



