#include <iostream>

using namespace std; //std 이름공간 사용 추가

int main() //main함수 맨앞 소문자로 변경, 세미콜론 삭제
{
    int a, b, c, sum; //c에 대입하는 수의 크기가 short 범위를 넘어서므로 int형으로 변경
    float d, e; //세미콜론 추가

    a = 12;
    b = 5678;
    c = 123456;
    sum = a+b+c;
    cout<<a<<b<<c;
    cout<<sum; //std 사용을 앞에서 밝혀주므로 std::를 삭제하고, out을 cout으로 변경.
}