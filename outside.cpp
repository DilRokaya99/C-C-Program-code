#include<iostream>
#include<conio.h>
using namespace std;
class rectangle{
    int l,b;
    public:
    void read();
    void write();
};
void rectangle::read(){
    cin>>l>>b;
}
void rectangle::write(){
    cout<<l*b;
}
int main(){
    rectangle r1;
    r1.read();
    r1.write();
    getch();
    return 0;
}