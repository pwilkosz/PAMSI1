__start__: a.out
	./a.out
a.out: main.o algorytm.o statystyki.o operacje.o
	g++ main.o algorytm.o statystyki.o operacje.o
main.o: src/main.cpp inc/algorytm.hh
	g++ -c -Wall -Iinc -pedantic src/main.cpp
algorytm.o: src/algorytm.cpp inc/algorytm.hh
	g++ -c -Wall -Iinc -pedantic src/algorytm.cpp
statystyki.o: src/statystyki.cpp inc/statystyki.hh
	g++ -c -Wall -Iinc -lm -pedantic src/statystyki.cpp
operacje.o: src/operacje.cpp inc/operacje.hh
	g++ -c -Wall -Iinc -pedantic src/operacje.cpp
clean:
	rm -f *.o