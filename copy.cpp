#include<iostream>
#include<conio.h>
using namespace std;
class rectangle{
    int l,b;
    public:
    rectangle(int len,int br){
        l=len;
        b=br;
    }
    void area(){
        cout<<l*b;
    }
};
int main(){
    rectangle r1(3,4),r2(r1);
    r1.area();
    r2.area();
    getch();
    return 0;
}