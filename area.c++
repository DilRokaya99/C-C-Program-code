#include<iostream>
#include<conio.h>
using namespace std;
int area(int l,int b){
    return l*b;
}
float area(float r){
    return 3.14*r*r;
}
int main(){
    int l,b,ch;
    float r;
    cout<<"1.area\n2.circle";
    cout<<"\nenter any choice:";
    cin>>ch;
    switch(ch){
    case 1:
    cout<<"\nenter a length:";
    cin>>l;
    cout<<"\nenter a breadth:";
    cin>>b;
    cout<<area(l,b);
    break;
    case 2:
    cout<<"enter a radius of circle:";
    cin>>r;
    cout<<area(r);
    break;
    default:
    cout<<"invalid choice";
    }
    return 0;
}
