FLAGS = -O2

all: test1

Simplex.o: Simplex.cpp Simplex.h
	g++ $(FLAGS) -c Simplex.cpp

test1: test1.cpp Simplex.o
	g++ $(FLAGS) test1.cpp Simplex.o -o test1

clean:
	rm -f *.o test1

#---------------------------------------------------
# main: main.cpp Clique.o 
# 	g++ ${FLAGS} main.cpp Clique.o  -o main
