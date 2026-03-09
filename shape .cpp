#include<iostream>
#include<conio.h>
using namespace std;
int area(int l,int b){
    return l*b;
}
int area(int l){
    return l*l;
}
int area(float r){
    return 3.14*r*r;
}
float area(int a,int b,int c){
    float s=a+b+c/2;
    return s*s-a*s-b*s-c;
}
int main (){
    int c,l,b,r;
    float s1,s2,s3;
    cout<<"enter choice:\n1.area\n2.squar\n3.circle\n4.tringle\nchoice:";
    cin>>c;
    switch(c){
    case 1:
    cout<<"enter length and breadth:";
    cin>>l>>b;
    cout<<"area="<<area(l,b);
    break;
    case 2:
    cout<<"enter length:";
    cin>>l;
    cout<<"sqare="<<area(l);
    break;
    case 3:
    cout<<"enter a radius of circle:";
    cin>>r;
    cout<<"circle:"<<area(r);
    break;
    case 4:
    cout<<"enter any shape:";
    cin>>s1>>s2>>s3;
    cout<<"area of tringle="<<area(s1,s2,s3);
    break;
    default:
    cout<<"ERROR";
    }
}