#include <iostream>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include <string>
#include "INIT.h"
#include "Snake.h"
#include "Map.h"
#include "GameWindow.h"
#include "Item.h"

using namespace std;

int main(){
    int x=0, y=0;
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    init();
    string filename = "map1.txt";
    Map M = Map();
    M.LoadMap(filename);
    Snake S = Snake(M.getSnake());
    GameWindow G = GameWindow();
    Item I = Item(M.getRow(), M.getCol());
    while(true){
        I.makeItem(M.getMap(), S.getBODY(), chrono::system_clock::now());
        I.mapWithItem(M.getMap());
        S.update(I.getMap());
        I.delItem(S.head());
        G.ReadyToPrintMap(I.getMap(), S.getBODY());
        G.Print();
        if(S.Died())
            break;
    }
    endwin();
    return 0;
}