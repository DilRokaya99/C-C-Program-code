#include<iostream>
#include<conio.h>
using namespace std;
class dil{
    int money=30;
    friend void vm(dil);
};
void vm(dil d1){
    cout<<d1.money;
}
int main(){
    dil obj;
    vm(obj);
    getch();
    return 0;
}