main : main.o Pos.o INIT.o Snake.o Map.o GameWindow.o Item.o Gate.o ScoreWindow.o MissionWindow.o
	g++ -g -o main main.o Pos.o INIT.o Snake.o Map.o GameWindow.o Item.o Gate.o ScoreWindow.o MissionWindow.o -lncursesw

main.o : main.cpp Pos.h INIT.h Snake.h Map.h GameWindow.h Item.h
	g++ -g -c main.cpp -lncursesw

Pos.o : Pos.cpp Pos.h
	g++ -g -c Pos.cpp -lncursesw

INIT.o : INIT.cpp INIT.h
	g++ -g -c INIT.cpp -lncursesw

Snake.o : Snake.cpp Snake.h Pos.h Map.h
	g++ -g -c Snake.cpp -lncursesw

Map.o : Map.cpp Map.h Pos.h item_type.h
	g++ -g -c Map.cpp -lncursesw

GameWindow.o : GameWindow.cpp GameWindow.h Pos.h
	g++ -g -c GameWindow.cpp -lncursesw

Item.o : Item.cpp Item.h Pos.h item_type.h
	g++ -g -c Item.cpp -lncursesw

Gate.o : Gate.cpp Gate.h Pos.h
	g++ -g -c Gate.cpp -lncursesw

ScoreWindow.o : ScoreWindow.cpp ScoreWindow.h
	g++ -g -c ScoreWindow.cpp -lncursesw

MissionWindow.o : MissionWindow.cpp MissionWindow.h
	g++ -g -c MissionWindow.cpp -lncursesw