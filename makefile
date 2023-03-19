comp = g++
flags = -g -Wall

main: main.o ll.o
	$(comp) $(flags) -o main main.o ll.o

main.o: main.cpp ll.h
	$(comp) $(flags) -c main.cpp

ll.o: ll.cpp ll.h
	$(comp) $(flags) -c ll.cpp

clean:
	rm -f main main.o ll.o
