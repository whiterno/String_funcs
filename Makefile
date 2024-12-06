a.out: main.o
	g++ main.o

main.o: main.cpp mstring.h
	g++ -c main.cpp -o main.o
