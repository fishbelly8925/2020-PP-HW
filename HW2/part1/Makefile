pi.out: pi.o
	g++ -pthread -o pi.out pi.o
pi.o: pi.cpp
	g++ -c pi.cpp

clean:
	rm -f pi.o pi.out
