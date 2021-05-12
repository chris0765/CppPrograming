#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    char text[30];
    ifstream fin;
    fin.open("./2-1.cpp");
    if(!fin){
        cout<<"읽기파일 인식 실패"<<endl;
        return 0;
    }
    ofstream fout("./2-1.txt");
    if(!fout){
        cout<<"쓰기파일 인식 실패"<<endl;
        return 0;
    }
    int check;
    int cnt=1;
    cout<<setw(3)<<setfill('0')<<cnt<<" : ";
    fout<<setw(3)<<setfill('0')<<cnt++<<" : ";
    while((check=fin.get()) != EOF){
        cout<<char(check);
        fout.put(char(check));
        if(char(check)=='\n'){
            cout<<setw(3)<<setfill('0')<<cnt<<" : ";
            fout<<setw(3)<<setfill('0')<<cnt++<<" : ";
        }
    }
    cout<<endl;
    fout<<endl;
    fin.close();
    fout.close();
    return 0;
}