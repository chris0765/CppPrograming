#include <iostream>

using namespace std;

class Counter {
    int count;
    const int increment;
    public:
        Counter(int c=0, int i=1);
        void Increase() { count += increment;}
        void Print() const;
};

Counter::Counter(int c, int i):increment(i){
    count = c;
}

void Counter::Print() const{
    cout<<" count = "<<count<<", increment = "<<increment<<endl;
}

int main(){
    Counter c1 {10};
    Counter c2 {20, 10};

    for(int i=0; i<3; i++){
        c1.Increase();
        cout<<"Count "<<i+1<< ": ";
        c1.Print();
    }

    for(int i=0; i<3; i++){
        c2.Increase();
        cout<<"Count "<<i+1<<": ";
        c1.Print();
    }
    return 0;
}