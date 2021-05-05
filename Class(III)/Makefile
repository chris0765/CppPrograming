CC = g++
OBJECTS = TestMyComplex.o MyComplex.o TestMyMatrix.o MyMatrix.o TestMyPolynomial.o MyPolynomial.o MyTerm.o

TestMyPolynomial : TestMyPolynomial.o MyPolynomial.o MyTerm.o
	$(CC) -g -o TestMyPolynomial MyTerm.o MyPolynomial.o TestMyPolynomial.o

TestMyPolynomial.o : TestMyPolynomial.cpp MyPolynomial.h
	$(CC) -g -c TestMyPolynomial.cpp

MyPolynomial.o : MyPolynomial.cpp MyPolynomial.h MyTerm.h
	$(CC) -g -c MyPolynomial.cpp

MyTerm.o : MyTerm.cpp MyTerm.h
	$(CC) -g -c MyTerm.cpp

TestMyMatrix : TestMyMatrix.o MyMatrix.o
	$(CC) -g -o TestMyMatrix MyMatrix.o TestMyMatrix.o

TestMyMatrix.o : TestMyMatrix.cpp MyMatrix.h
	$(CC) -g -c TestMyMatrix.cpp

MyMatrix.o : MyMatrix.cpp MyMatrix.h
	$(CC) -g -c MyMatrix.cpp

TestMyComplex : TestMyComplex.o MyComplex.o
	$(CC) -g -o TestMyComplex MyComplex.o TestMyComplex.o

TestMyComplex.o : TestMyComplex.cpp MyComplex.h
	$(CC) -g -c TestMyComplex.cpp

MyComplex.o : MyComplex.cpp MyComplex.h
	$(CC) -g -c MyComplex.cpp

clean:
	rm TestMyComplex TestMyMatrix $(OBJECTS)