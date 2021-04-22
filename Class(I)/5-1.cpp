#include <iostream>

using namespace std;

class Time {  // Time class definition

private:

    int  hour;  // 0 ~ 23

    int  minute;  // 0 ~ 59

    int  second;  // 0 ~ 59

public:

    void setTime(int, int, int); // set hour, minute,   //     second

    void printTime12();  // 12시간 단위 출력

    void printTime24();  // 24시간 단위 출력

};

void Time::setTime( int h, int m, int s )

{

    hour  = ( h >= 0 && h < 24 ) ? h : 0;

    minute = ( m >= 0 && m < 60 ) ? m : 0;

    second = ( s >= 0 && s < 60 ) ? s : 0;

}

 

void Time::printTime24()

{

    cout << ( hour < 10 ? "0" : "" ) << hour << ":"

         << ( minute < 10 ? "0" : "" ) << minute;

}

void Time::printTime12()

{

   cout << ( hour < 12 ? "오전 " : "오후 " )

   << ((hour == 0 || hour == 12) ? 12 : hour % 12 )

   << ":" << ( minute < 10 ? "0" : "" ) << minute

   << ":" << (second < 10 ? "0" : "" ) << second

   << "\n";

}

int main()

{

    Time t_class;  // instantiates object t of class Time
    Time t_lunch;
    Time t_dinner;
    Time t_sleep;

 

    t_class.setTime( 11, 0, 0 );
    t_lunch.setTime( 12, 30, 0 );
    t_dinner.setTime( 18, 30, 0 );
    t_sleep.setTime( 0, 30, 0 );

    cout <<"수업시간 : ";t_class.printTime24();cout<<", ";t_class.printTime12();cout<<endl;
    cout <<"점심시간 : ";t_lunch.printTime24();cout<<", ";t_lunch.printTime12();cout<<endl;
    cout <<"저녁시간 : ";t_dinner.printTime24();cout<<", ";t_dinner.printTime12();cout<<endl;
    cout <<"취침시간 : ";t_sleep.printTime24();cout<<", ";t_sleep.printTime12();cout<<endl;

    return 0;

}