#include "Item.h"

Item::Item(int R, int C): row(R), col(C){};

void Item::makeItem(vector<vector<int>> Map, vector<Pos> BODY, chrono::time_point<chrono::system_clock> gametime){
    // 생성된 아이템이 없거나, 마지막 아이템이 생성된 후 5초가 지났다면 최대 3개까지 아이템 생성
    // 4개까지 생성은 되나, 4개째는 생성 후 바로 다음 조건문에서 삭제됨
    if(items.size() == 0 || (items.size() < 4 && chrono::duration_cast<chrono::milliseconds>(gametime - items[items.size()-1].droptime).count() > 5000)){
        random_device rd; // 랜덤한 좌표로 생성
        mt19937 gen(rd());
        uniform_int_distribution<int> randrow(0, row-1);
        uniform_int_distribution<int> randcol(0, col-1);
        uniform_int_distribution<int> randitem(0, 4);
        bool check = false;
        int torow=0, tocol=0;
        int item_spec[5] = {5, 6, 5, 6, 5}; // Grow와 Poison의 생성 확률 비율을 3:2로 설정

        do{
            check = false;
            torow = randrow(gen);
            tocol = randcol(gen);
            // 생성된 좌표가 Snake와 겹치거나, 타 아이템에 겹치거나, 벽과 겹치면 좌표를 다시 생성
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
    // 아이템이 3개 전부 생성된 상태라면, 가장 오래된 아이템 삭제
    if(items.size() > 0 && items.size() == 4 && chrono::duration_cast<chrono::milliseconds>(gametime - items[0].droptime).count() > 5000)
        items.erase(items.begin());
}

// Snake의 머리와 아이템이 겹친다면, 해당하는 아이템을 삭제함
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