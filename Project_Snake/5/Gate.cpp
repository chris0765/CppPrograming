#include "Gate.h"

Gate::Gate(int R, int C): row(R), col(C){};

bool Gate::makeGates(vector<vector<int>> map, int score, chrono::time_point<chrono::system_clock> nowtime, bool isWarped){
    if(score >= 5 && gates.empty()){ // 게이트가 없는 상태에서 Grow 아이템을 5개 섭취 시 게이트 생성
        random_device rd; // 범위 내에 게이트 좌표 생성
        mt19937 gen(rd());
        uniform_int_distribution<int> randrow(0, row-1);
        uniform_int_distribution<int> randcol(0, col-1);
        bool check = false;
        int torow = 0, tocol = 0;

        do{
            check = true;
            torow = randrow(gen);
            tocol = randcol(gen);
            int d[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
            for(int i=0; i<4; i++){
                int nextx = torow + d[i][0];
                int nexty = tocol + d[i][1];
                if(nextx < 0 || row <= nextx || nexty < 0 || col <= nexty){
                    continue;
                }
                if(map[nextx][nexty] != 1 && map[nextx][nexty] != 2){
                    check = false;
                }
            }
        } while(map[torow][tocol] != 1 || check); // 게이트가 벽 위에 생성되지 않았다면(Immune Wall 제외) 좌표 재생성, 게이트의 사방이 모두 막혀있다면 좌표 재생성
        gates.push_back({torow, tocol});
        do{
            check = false;
            torow = randrow(gen);
            tocol = randcol(gen);
            int d[4][2] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};
            for(int i=0; i<4; i++){
                int nextx = torow + d[i][0];
                int nexty = tocol + d[i][1];
                if(nextx < 0 || row <= nextx || nexty < 0 || col <= nexty){
                    continue;
                }
                if(map[nextx][nexty] != 1 && map[nextx][nexty] != 2){
                    check = false;
                }
            }
        } while(map[torow][tocol] != 1 || (torow == gates[0].getX() && tocol == gates[0].getY()) || check); // 나머지 게이트쌍도 마찬가지로 생성. 다른 쌍과 좌표가 겹치지 않도록 한다.
        gates.push_back({torow, tocol});
        madetime = nowtime; // 게이트가 생성된 시각 저장
    }
    if(chrono::duration_cast<chrono::milliseconds>(nowtime - madetime).count() > 15000 && isWarped == false){ // 게이트가 생성된지 15초가 지났고, Snake가 게이트를 통과하고 있지 않다면 게이트 삭제
        gates.clear();
        return true;
    }
    return false;
}

// 게이트 통과 후 머리의 좌표
Pos Gate::headPath(vector<vector<int>> map, Pos t, char d){
    if(!gates.empty() && t.getX() == gates[0].getX() && t.getY() == gates[0].getY()){
        if(d == 'l'){
            if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return {gates[1].getX(), gates[1].getY()-1};
            else if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return {gates[1].getX()-1, gates[1].getY()};
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return {gates[1].getX()+1, gates[1].getY()};
            else if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return {gates[1].getX(), gates[1].getY()+1};
        }
        else if(d == 'r'){
            if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return {gates[1].getX(), gates[1].getY()+1};
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return {gates[1].getX()+1, gates[1].getY()};
            else if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return {gates[1].getX()-1, gates[1].getY()};
            else if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return {gates[1].getX(), gates[1].getY()-1};
        }
        else if(d == 'u'){
            if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return {gates[1].getX()-1, gates[1].getY()};
            else if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return {gates[1].getX(), gates[1].getY()+1};
            else if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return {gates[1].getX(), gates[1].getY()-1};
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return {gates[1].getX()+1, gates[1].getY()};
        }
        else if(d == 'd'){
            if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return {gates[1].getX(), gates[1].getY()-1};
            else if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return {gates[1].getX()-1, gates[1].getY()};
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return {gates[1].getX()+1, gates[1].getY()};
            else if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return {gates[1].getX(), gates[1].getY()+1};
        }
    }
    if(!gates.empty() && t.getX() == gates[1].getX() && t.getY() == gates[1].getY()){
        if(d == 'l'){
            if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return {gates[0].getX(), gates[0].getY()-1};
            else if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return {gates[0].getX()-1, gates[0].getY()};
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return {gates[0].getX()+1, gates[0].getY()};
            else if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return {gates[0].getX(), gates[0].getY()+1};
        }
        else if(d == 'r'){
            if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return {gates[0].getX(), gates[0].getY()+1};
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return {gates[0].getX()+1, gates[0].getY()};
            else if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return {gates[0].getX()-1, gates[0].getY()};
            else if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return {gates[0].getX(), gates[0].getY()-1};
        }
        else if(d == 'u'){
            if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return {gates[0].getX()-1, gates[0].getY()};
            else if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return {gates[0].getX(), gates[0].getY()+1};
            else if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return {gates[0].getX(), gates[0].getY()-1};
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return {gates[0].getX()+1, gates[0].getY()};
        }
        else if(d == 'd'){
            if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return {gates[0].getX(), gates[0].getY()-1};
            else if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return {gates[0].getX()-1, gates[0].getY()};
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return {gates[0].getX()+1, gates[0].getY()};
            else if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return {gates[0].getX(), gates[0].getY()+1};
        }
    }
    return t; // 게이트를 통과하지 않는다면 기존 머리 좌표를 그대로 리턴
}

// 게이트 통과 후 진행 방향
char Gate::dirPath(vector<vector<int>> map, Pos t, char d){
    if(!gates.empty() && t.getX() == gates[0].getX() && t.getY() == gates[0].getY()){
        if(d == 'l'){
            if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return 'l';
            else if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return 'u';
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return 'd';
            else if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return 'r';
        }
        else if(d == 'r'){
            if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return 'r';
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return 'd';
            else if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return 'u';
            else if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return 'l';
        }
        else if(d == 'u'){
            if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return 'u';
            else if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return 'r';
            else if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return 'l';
            else if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return 'd';
        }
        else if(d == 'd'){
            if(gates[1].getX()+1<row && (map[gates[1].getX()+1][gates[1].getY()] != 1 && map[gates[1].getX()+1][gates[1].getY()] != 2))
                return 'd';
            else if(gates[1].getY()-1>=0 && (map[gates[1].getX()][gates[1].getY()-1] != 1 && map[gates[1].getX()][gates[1].getY()-1] != 2))
                return 'l';
            else if(gates[1].getY()+1<col && (map[gates[1].getX()][gates[1].getY()+1] != 1 && map[gates[1].getX()][gates[1].getY()+1] != 2))
                return 'r';
            else if(gates[1].getX()-1>=0 && (map[gates[1].getX()-1][gates[1].getY()] != 1 && map[gates[1].getX()-1][gates[1].getY()] != 2))
                return 'u';
        }
    }
    if(!gates.empty() && t.getX() == gates[1].getX() && t.getY() == gates[1].getY()){
        if(d == 'l'){
            if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return 'l';
            else if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return 'u';
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return 'd';
            else if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return 'r';
        }
        else if(d == 'r'){
            if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return 'r';
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return 'd';
            else if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return 'u';
            else if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return 'l';
        }
        else if(d == 'u'){
            if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return 'u';
            else if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return 'r';
            else if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return 'l';
            else if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return 'd';
        }
        else if(d == 'd'){
            if(gates[0].getX()+1<row && (map[gates[0].getX()+1][gates[0].getY()] != 1 && map[gates[0].getX()+1][gates[0].getY()] != 2))
                return 'd';
            else if(gates[0].getY()-1>=0 && (map[gates[0].getX()][gates[0].getY()-1] != 1 && map[gates[0].getX()][gates[0].getY()-1] != 2))
                return 'l';
            else if(gates[0].getY()+1<col && (map[gates[0].getX()][gates[0].getY()+1] != 1 && map[gates[0].getX()][gates[0].getY()+1] != 2))
                return 'r';
            else if(gates[0].getX()-1>=0 && (map[gates[0].getX()-1][gates[0].getY()] != 1 && map[gates[0].getX()-1][gates[0].getY()] != 2))
                return 'u';
        }
    }
    return d; // 게이트를 통과하지 않는다면 기존의 진행 방향 그대로 리턴
}

vector<Pos> Gate::getGates(){
    return gates;
}