#EXERCISE 0: fix mistakes so that this file actually work! hint: there is a confusion of where we store object files
# #scr/hello.cpp corrected at line 11: hello.o files is src folder

# This is a comment line
CC=g++
# This is a folder to look for header files
INCDIR=include
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -I$(INCDIR) -Wall -03

hello.x: main.o src/hello.o
	$(CC) main.o src/hello.o -o hello.x 
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -std=c++14
src/hello.o: src/hello.cpp
	$(CC) $(CFLAGS) hello.cpp -std=c++14
clean:
	rm -rf src/*.o *.x 
	
