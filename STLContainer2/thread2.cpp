#include <iostream>
#include <thread>
#include <cmath>
#include <mutex>

using namespace std;
using namespace std::chrono;

void myThread(const int a, const int b, long *sum){
    for(int i=a; i<=b; i++){
        *sum+=i;
    }
}

int main(){
    long sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    thread t1(myThread, 1, 25000, &sum1);
    thread t2(myThread, 25001, 50000, &sum2);
    thread t3(myThread, 50001, 75000, &sum3);
    thread t4(myThread, 75001, 100000, &sum4);
    if(t1.joinable()) t1.join();
    if(t2.joinable()) t2.join();
    if(t3.joinable()) t3.join();
    if(t4.joinable()) t4.join();

    sum = sum1 + sum2 + sum3 + sum4;
    cout<<sum<<endl;

    return 0;
}