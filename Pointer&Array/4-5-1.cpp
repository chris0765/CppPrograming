#include <iostream>

using namespace std;

// Time 표현을 위한 구조체를 정의하고 강의시간을 12시간/24시간 단위로 출력하기
struct Time {  // structure definition
    int  hour;  // 0~23
    int  minute;  // 0~59
    int  second;  // 0~59
} ;
void printTime12( const Time & );  // 12시간 단위 출력 (오전/오후 11:00:00)
void printTime24( const Time & );  // 24시간 단위 출력 (23:59:59)
 
void printTime12( const Time &t)
{
    cout << ( t.hour < 12 ? "오전" : "오후" )
            << ( ( t.hour == 0 || t.hour == 12 ) ? 12 : t.hour % 12 )
            << ":" << ( t.minute < 10 ? "0" : "" ) << t.minute
            << ":" << (t.second < 10 ? "0" : "" ) << t.second
            << "\n";
}
 
void printTime24( const Time &t)
{
    cout << t.hour 
        << ":" << (t.minute < 10 ? "0" : "") << t.minute 
        << endl;
}
 
int main()
{
    struct Time t = {23, 0, 0};
    printTime12(t);
    printTime24(t);
    return 0;
}