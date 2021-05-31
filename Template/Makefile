CC = g++
CCFLAGS = -g

main : main.o team.o Kvector.o
	$(CC) $(CCFLAGS) -o main main.o team.o Kvector.o

main.o : main.cpp team.h Kvector.h
	$(CC) $(CCFLAGS) -c main.cpp team.h Kvector.h

team.o : team.cpp team.h
	$(CC) $(CCFLAGS) -c team.cpp

Kvector.o : Kvector.cpp Kvector.h
	$(CC) $(CCFLAGS) -c Kvector.cpp

clean:
	rm -f %.o
