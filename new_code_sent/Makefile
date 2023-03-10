SRC = $(wildcard *.cpp)
OBJ = $(patsubst %.cpp, %.o, $(SRC))

prog: $(OBJ)
	g++ project2.cpp subexpression.o operand.o symboltable.o variable.o parse.o -o project2

%.o: %.cpp
	  $(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o project2
