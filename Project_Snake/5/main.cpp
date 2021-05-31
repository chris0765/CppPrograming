#include <iostream>
#include "INIT.h"
#include "Snake.h"
#include "Map.h"
#include "GameWindow.h"
#include "Item.h"
#include "Gate.h"
#include "ScoreWindow.h"
#include "MissionWindow.h"

using namespace std;

int main(){
    chrono::time_point<chrono::system_clock> start = chrono::system_clock::now(); // 프로그램 시작 시간
    init(); // 출력 윈도우 설정 // INIT.h
    GameWindow GW = GameWindow(); // 게임이 진행되는 화면을 관리하는 객체 생성
    int level = 1; // 레벨에 따라 맵과 미션의 난이도 설정
    string filename = "Start.txt"; // 게임 시작 화면
    Map M = Map(); // 맵 클래스
    M.LoadMap(filename);
    Snake S = Snake(M.getSnake()); // 맵 데이터에 존재하는 Snake의 데이터 불러와 객체 생성
    nodelay(stdscr, false);
    GW.ReadyToPrintMap(M.getTotalMap(), S.getBODY());
    GW.Print();
    do{
        char key = getch();
        if(key == 'e')
            break;
    }while(true); // e키를 누르면 시작
    nodelay(stdscr, TRUE);
    filename = "map1.txt"; // 첫 맵
    M.LoadMap(filename); // 텍스트 파일에 있는 맵 데이터 불러옴
    S = Snake(M.getSnake()); // 맵 데이터에 존재하는 Snake의 데이터 불러와 객체 생성
    ScoreWindow SW = ScoreWindow(S.getLength(), M.getCol()); // 스코어를 보여주는 화면을 관리하는 객체 생성
    MissionWindow MW = MissionWindow(M.getCol()); // 미션을 보여주는 화면을 관리하는 객체 생성
    MW.setNew(level); // 레벨에 따라 미션 부여
    Item I = Item(M.getRow(), M.getCol()); // Grow, Poison 아이템을 관리하는 객체 생성
    Gate G = Gate(M.getRow(), M.getCol()); // 게이트를 관리하는 객체 생성
    while(true){
        I.makeItem(M.getMap(), S.getBODY(), chrono::system_clock::now()); // 시간에 따라 아이템 생성, Snake, Wall과 겹치지 않는 위치에 생성한다.
        G.makeGates(M.getMap(), S.getGrowScore(), chrono::system_clock::now(), S.Warp()); // 점수에 따라 게이트 생성, Wall 위에 생성한다.
        M.MakeMap(I.getItem(), G.getGates()); // 아이템과 게이트를 합쳐서 맵에 표시한다.
        Pos nexthead = G.headPath(M.getTotalMap(), S.nextHead(), S.getDirection()); // Snake의 머리가 다음 틱에 어디에 있을지를 구한다.(게이트 통과 포함)
        S.update(M.getTotalMap(), nexthead, G.dirPath(M.getTotalMap(), S.nextHead(), S.getDirection())); // Snake를 업데이트하고, 방향 또한 업데이트 한다.(게이트 통과 포함)
        I.delItem(S.head()); // Snake가 특정 아이템을 먹었다면 해당하는 아이템을 삭제한다.
        SW.setValues(S.getLength(), S.growCount(), S.poisonCount(), S.warpCount()); // 스코어보드 갱신
        MW.setValues(S.getLength(), S.growCount(), S.poisonCount(), S.warpCount()); // 미션보드 갱신
        GW.ReadyToPrintMap(M.getTotalMap(), S.getBODY()); // 아이템과 게이트가 표시된 맵과 Snake를 합친다. 
        GW.Print(); // 위에서 합친 데이터를 출력
        SW.Print(); // 스코어보드 출력
        MW.Print(); // 미션보드 출력
        if(S.Died()){ // 죽었다면
            filename = "GameOver.txt"; // 게임 오버를 표시
            M.LoadMap(filename);
            S = Snake(M.getSnake());
            GW.ReadyToPrintMap(M.getTotalMap(), S.getBODY());
            GW.Print();
            break; // 이후 탈출
        }
        if(MW.isClear()){ // 미션을 모두 클리어했다면
            level++; // 다음 레벨로 증가
            filename = "map" + to_string(level) + ".txt";
            if(access(filename.c_str(), F_OK) != 0){ // 찾고자 하는 맵이 없다면 == 마지막 단계의 맵까지 클리어 == 게임 클리어
                filename = "Clear.txt"; // 게임 클리어를 표시
                M.LoadMap(filename);
                S = Snake(M.getSnake());
                GW.ReadyToPrintMap(M.getTotalMap(), S.getBODY());
                GW.Print();
                break; // 이후 탈출
            }
            M.LoadMap(filename); // 찾는 맵이 있다면 해당 맵을 표시
            S = Snake(M.getSnake());
            SW = ScoreWindow(S.getLength(), M.getCol());
            MW =MissionWindow(M.getCol());
            MW.setNew(level);
            I = Item(M.getRow(), M.getCol());
            G = Gate(M.getRow(), M.getCol());
        }
    }
    usleep(10000000); // 게임 종료 후 1초간 종료 화면 노출
    endwin();
    return 0;
}