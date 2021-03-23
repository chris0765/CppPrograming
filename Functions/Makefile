CC = g++
OBJECTS = dicetest.o random.o

dicetest : dicetest.o random.o
	$(CC) -g -o dicetest random.o dicetest.o

dicetest.o : dicetest.cpp random.h
	$(CC) -g -c dicetest.cpp

random.o : random.cpp random.h
	$(CC) -g -c random.cpp

clean:
	rm dicetest $(OBJECTS)