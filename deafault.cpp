#include<iostream>
#include<conio.h>
using namespace std;
class rectangle{
    int l,b;
    public:
rectangle (){
   l=2;
   b=1;
}
void area(){
    cout<<l*b;
}
};
int main(){
    rectangle r1;
    r1.area();
    getch();
    return 0;
}