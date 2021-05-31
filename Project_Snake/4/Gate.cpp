#include "Gate.h"

Gate::Gate(int R, int C): row(R), col(C){};

bool Gate::makeGates(vector<vector<int>> map, int score, chrono::time_point<chrono::system_clock> nowtime, bool isWarped){
    if(score >= 5 && gates.empty()){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> randrow(0, row-1);
        uniform_int_distribution<int> randcol(0, col-1);
        bool check = false;
        int torow = 0, tocol = 0;

        do{
            check = false;
            torow = randrow(gen);
            tocol = randcol(gen);
        } while(map[torow][tocol] != 1);
        gates.push_back({torow, tocol});
        do{
            check = false;
            torow = randrow(gen);
            tocol = randcol(gen);
        } while(map[torow][tocol] != 1 || (torow == gates[0].getX() && tocol == gates[0].getY()));
        gates.push_back({torow, tocol});
        madetime = nowtime;
    }
    if(chrono::duration_cast<chrono::milliseconds>(nowtime - madetime).count() > 15000 && isWarped == false){
        gates.clear();
        return true;
    }
    return false;
}

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
    return t;
}

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
    return d;
}

vector<Pos> Gate::getGates(){
    return gates;
}