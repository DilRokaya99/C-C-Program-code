#include<iostream>
#include<conio.h>
using namespace std;
class rectangle{
int l,b;
public:
void input();
void area();
};
void rectangle::input(){
    cin>>l>>b;
}
void rectangle::area(){
   cout<<l*b;
}
int main(){
    rectangle r1(4,6);
    r1.input();
    r1.area();
    return 0;
    getch();
}