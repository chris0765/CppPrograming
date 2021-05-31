CC = g++
CCFLAGS = -g

BitSet: BitSet.o Bvector.o Kvector.o
	$(CC) $(CCFLAGS) -o BitSet BitSet.o Bvector.o Kvector.o

Bvector: main.o Bvector.o Avector.o Kvector.o
	$(CC) $(CCFLAGS) -o Bvector main.o Bvector.o Avector.o Kvector.o

clean:
	rm -f *.o

%.o : %.cpp %.h
	$(CC) $(CCFLAGS) -c $<

%.o : %.cpp
	$(CC) $(CCFLAGS) -c $<

% : %.cpp
	$(CC) $(CCFLAGS) -o $<
