#include "Item.h"
#include <iostream>

Item::Item(int R, int C): row(R), col(C){};

void Item::makeItem(vector<vector<int>> Map, vector<Pos> BODY, chrono::time_point<chrono::system_clock> gametime){
    if(items.size() == 0 || (items.size() < 4 && chrono::duration_cast<chrono::milliseconds>(gametime - items[items.size()-1].droptime).count() > 5000)){
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> randrow(0, row-1);
        uniform_int_distribution<int> randcol(0, col-1);
        uniform_int_distribution<int> randitem(0, 1);
        bool check = false;
        int torow=0, tocol=0;
        int item_spec[2] = {5, 6};

        do{
            check = false;
            torow = randrow(gen);
            tocol = randcol(gen);
            for(int i=0; i<BODY.size(); i++){
                if(BODY[i].getX() == torow && BODY[i].getY() == tocol){
                    check = true;
                    break;
                }
                if(BODY[i].getX()-2<torow&&BODY[i].getX()+2>torow&&BODY[i].getY()-2<tocol&&BODY[i].getY()+2>tocol){
                    check = true;
                    break;
                }
                if(Map[torow][tocol] != 0){
                    check = true;
                    break;
                }
                for(int i=0; i<items.size(); i++)
                    if(torow == items[i].pos.getX() && tocol == items[i].pos.getY()){
                        check = true;
                        break;
                    }
            }
        } while(check);
        items.push_back({{torow, tocol}, item_spec[randitem(gen)], gametime});
    }
    if(items.size() > 0 && items.size() == 4 && chrono::duration_cast<chrono::milliseconds>(gametime - items[0].droptime).count() > 5000)
        items.erase(items.begin());
}

void Item::delItem(Pos head){
    for(int i=0; i<items.size(); i++)
        if(head.getX() == items[i].pos.getX() && head.getY() == items[i].pos.getY()){
            items.erase(items.begin() + i);
            break;
        }
}

vector<item_type> Item::getItem(){
    return items;
}