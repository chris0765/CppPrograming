#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    ifstream fin("./3-1.cpp", ios::in | ios::binary);

    if(!fin){
        cout<<"읽기 파일 인식 실패"<<endl;
        return 0;
    }

    char s[16];

    cout.unsetf(ios::dec);
    cout.setf(ios::hex);
    cout.setf(ios::uppercase);

    while(!fin.eof()){
        fin.read(s, 16);
        int n = fin.gcount();
        for(int i=0; i<n; i++)
            cout<<setw(2)<<setfill('0')<<int(s[i])<<" ";
        cout<<endl;
    }
    cout<<endl;
    return 0;
}