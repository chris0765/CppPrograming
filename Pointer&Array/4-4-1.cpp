#include <iostream>
#include <cstring>

using namespace std;

char* string_copy(char* dst, const char* src)
{
    dst = new char[strlen(src)+1];
    for(int i=0; i<strlen(src)+1; i++)
        dst[i]=src[i];
    return dst;
}

int main()
{
    char* arr_origin = new char[80];
    char* arr_made;
    cin.getline(arr_origin, 80);
    arr_made=string_copy(arr_made, arr_origin);
    cout<<arr_made<<endl;
    delete arr_origin;
    delete arr_made;
    return 0;
}