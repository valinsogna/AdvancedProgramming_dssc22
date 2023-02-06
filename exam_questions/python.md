1. How do you create markdown cell in Jupyter? (with keyboard commands)

2. How do you delete a cell in Jupyter (with keyboard command)?

3. How do you add a cell above the current one in Jupyter (with keyboard command)?

4. What advantage does conda environment provide over a system-wide installation of python?

5. What does it mean that variables are dynamically typed in python?

6. What's the difference between python and C/C++ integers?

7. Explain the difference between lists, sets and tuples in python.

8. What does negative index mean when accessing list elements?

9. How do you print the first N elements of a list?

10. How do you print every Nth element of a list?

11. How do you print the reverse list?

12. Give an example of a list comprehension.

13. Give an example of cell and line magic commands in Jupyter.

14. Write a "hello world" function in python (syntax errors are not ok in hello world even on paper).

15. What are keyword function arguments in python and what is their advantage?

16. Why shouldn't you do `from numpy import *`?

17. What is the advantage of using numpy arrays over lists? What are the dangers?

18. What's the most widely used package for plotting in python?

19. What's the purpose of `__str__` method in a python class?

20. What package can you use in python for symbolic calculations?

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
```
 
 
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

22. Name two ways of calling c++ code from python.

23. What is pandas? Name at least 5 functions from that package.

