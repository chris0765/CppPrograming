#include <iostream>
#include <thread>

using namespace std;
using namespace std::chrono;

void myThread(){
    for(int i=0; i<5; i++){
        cout<<"world"<<endl;
        this_thread::sleep_for(milliseconds(500));
    }
}

int main(){
    thread t(myThread);
    for(int i=0; i<5; i++){
        cout<<"Hello"<<endl;
        this_thread::sleep_for(milliseconds(500));
    }
    return 0;
}