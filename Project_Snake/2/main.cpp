#include <iostream>
#include <chrono>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include "INIT.h"
#include "Snake.h"
#include "Map.h"
#include "GameWindow.h"

using namespace std;

int main(){
    int x=0, y=0;
    chrono::time_point<chrono::high_resolution_clock> start = chrono::high_resolution_clock::now();
    init();
    string filename = "map1.txt";
    Map M = Map();
    M.LoadMap(filename);
    Snake S = Snake(M.getSnake());
    GameWindow G = GameWindow();
    while(true){
        G.ReadyToPrintMap(M.getMap(), S.getBODY());
        G.Print();
        S.update();
        if(G.isFailed())
            break;
    }
    endwin();
    return 0;
}