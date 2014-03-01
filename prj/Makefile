a.out: main.o algorytm.o
	g++ main.o algorytm.o
main.o: src/main.cpp inc/algorytm.hh
	g++ -c -Wall -Iinc -pedantic src/main.cpp
algorytm.o: src/algorytm.cpp inc/algorytm.hh
	g++ -c -Wall -Iinc -pedantic src/algorytm.cpp