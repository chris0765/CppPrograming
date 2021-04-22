CC = g++
OBJECTS = main.o time1.o

main : main.o time1.o
	$(CC) -g -o main time1.o main.o

main.o : main.cpp time1.h
	$(CC) -g -c main.cpp

time1.o : time1.cpp time1.h
	$(CC) -g -c time1.cpp

clean:
	rm main $(OBJECTS)