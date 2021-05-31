main : main.o Pos.o INIT.o Snake.o Map.o GameWindow.o
	g++ -g -o main main.o Pos.o INIT.o Snake.o Map.o GameWindow.o -lncursesw

main.o : main.cpp Pos.h INIT.h Snake.h Map.h GameWindow.h
	g++ -g -c main.cpp -lncursesw

Pos.o : Pos.cpp Pos.h
	g++ -g -c Pos.cpp -lncursesw

INIT.o : INIT.cpp INIT.h
	g++ -g -c INIT.cpp -lncursesw

Snake.o : Snake.cpp Snake.h Pos.h
	g++ -g -c Snake.cpp -lncursesw

Map.o : Map.cpp Map.h Pos.h
	g++ -g -c Map.cpp -lncursesw

GameWindow.o : GameWindow.cpp GameWindow.h Pos.h
	g++ -g -c GameWindow.cpp -lncursesw