#include <iostream>

using namespace std;

class Date{
    int year;
    int month;
    int day;
    int checkDay(int);
    public:
        Date(int y = 1900, int m = 1, int d = 1);
        void printDate() const;
};

Date::Date(int y, int m, int d){
    year = y;
    month = m;
    day = d;
    if(1900 > y){
        cout << y <<"년은 잘못된 년도입니다."<<endl;
        y = 1900;
    }
    if(m < 1 || m > 12){
        cout << y << "년 " << m << "월은 잘못된 월입니다. " << endl;
        month = 1;
    }
    day = checkDay(d);
    year = y;
    month = m;
}

int Date::checkDay(int d){
    if(month == 2){
        if((year%4==0)&&(year%100!=0) ||(year%400 ==0)){
            if(d > 29){
                cout << year << "년 "<< month << "월 " << day << "일은 잘못된 날짜입니다."<<endl;
                return 1;
            }
            return d;
        }
        else{
            if(d > 28){
                cout << year << "년 "<< month << "월 " << day << "일은 잘못된 날짜입니다."<<endl;
                return 1;
            }
            return d;
        }
    }
    else{
        switch(month){
            case 4: case 6: case 9: case 11:
                if(d>30){
                    cout << year << "년 "<< month << "월 " << day << "일은 잘못된 날짜입니다."<<endl;
                    return 1;
                }
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(d>31){
                    cout << year << "년 "<< month << "월 " << day << "일은 잘못된 날짜입니다."<<endl;
                    return 1;
                }
            default:
                return d;
        }
    }
}

void Date::printDate() const{
    cout << year << "년 "<< month << "월 " << day << "일" << endl;
}

int main(){
    Date birthday(2021, 4, 13);
    Date badDay(1899, 2, 29);

    birthday.printDate();
    badDay.printDate();
    return 0;
}