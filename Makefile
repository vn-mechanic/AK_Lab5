all: main

main : main.o 

main.o: main.cpp
	g++ -o main main.cpp

clean:
	rm -rf *.o main
