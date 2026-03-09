#include<iostream>
using namespace std;
class cal{
    private:
    int x;
    public:
    cal():x(30){}
    void operator++(){
        x=x+30;
    }
    void print(){
        cout<<"operator "<<x<<endl;
    }
};
int main(){
    cal c;
    ++c;
    c.print();
    return 0;
}