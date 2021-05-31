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
#include "Gate.h"

using namespace std;

int main(){
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now();
    init();
    int cnt = 0;
    string filename = "map1.txt";
    Map M = Map();
    M.LoadMap(filename);
    Snake S = Snake(M.getSnake());
    GameWindow GW = GameWindow();
    Item I = Item(M.getRow(), M.getCol());
    Gate G = Gate(M.getRow(), M.getCol());
    while(true){
        I.makeItem(M.getMap(), S.getBODY(), chrono::system_clock::now());
        G.makeGates(M.getMap(), S.getGrowScore(), chrono::system_clock::now(), S.Warp());
        M.MakeMap(I.getItem(), G.getGates());
        Pos nexthead = G.headPath(M.getTotalMap(), S.nextHead(), S.getDirection());
        S.update(M.getTotalMap(), nexthead, G.dirPath(M.getTotalMap(), S.nextHead(), S.getDirection()));
        I.delItem(S.head());
        GW.ReadyToPrintMap(M.getTotalMap(), S.getBODY());
        GW.Print();
        if(S.Died())
            break;
    }
    endwin();
    return 0;
}