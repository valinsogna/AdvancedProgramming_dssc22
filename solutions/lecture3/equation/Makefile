# This is a comment line
CC=g++
# where to look for headers:
INCDIR=include
OBJDIR=obj# where to put object files: create it first!!!
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -I$(INCDIR)
OBJECTS= main.o $(OBJDIR)/coeffs.o $(OBJDIR)/eq.o 

eq.x: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp -std=c++14
obj/%.o: src/%.cpp  
	$(CC) $(CFLAGS) $^ -o $@ -std=c++14
clean:
	rm -rf obj/*.o *.x *.o
 
