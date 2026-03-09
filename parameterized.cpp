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
    rectangle r1(2,4);
    r1.area();
    getch();
    return 0;
}