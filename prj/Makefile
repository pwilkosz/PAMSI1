__start__: a.out
	./a.out
a.out: main.o algorytm.o statystyki.o operacje.o str_operacje.o graf.o simplex.o transport.o
	g++ -g -O0 main.o algorytm.o statystyki.o operacje.o str_operacje.o graf.o simplex.o transport.o -lrt
main.o: src/main.cpp inc/algorytm.hh
	g++ -c -Wall -g -Iinc -pedantic src/main.cpp
algorytm.o: src/algorytm.cpp inc/algorytm.hh inc/stos.hh inc/kolejka.hh inc/drzewo.hh inc/str_operacje.hh
	g++ -c -Wall -Iinc -pedantic src/algorytm.cpp -lrt
statystyki.o: src/statystyki.cpp inc/statystyki.hh
	g++ -c -Wall -Iinc -lm -pedantic src/statystyki.cpp
operacje.o: src/operacje.cpp inc/operacje.hh
	g++ -c -Wall -Iinc -pedantic src/operacje.cpp
str_operacje.o: src/operacje.cpp inc/str_operacje.hh
	g++ -c -Wall -Iinc -pedantic src/str_operacje.cpp
graf.o: src/graf.cpp inc/graf.hh
	g++ -c -Wall -Iinc -pedantic src/graf.cpp
simplex.o: src/simplex.cpp inc/simplex.hh
	g++ -c -Wall -Iinc -pedantic src/simplex.cpp
transport.o: src/transport.cpp inc/transport.hh
	g++ -c -Wall -Iinc -pedantic src/transport.cpp
clean:
	rm -f *.o