#include<iostream>
#include<conio.h>
using namespace std;
int main (){
    cout<<"variables with their size in byte";
    cout<<"\nsigned of char:"<<sizeof(signed char);
    cout<<"\nunsigned char:"<<sizeof(unsigned char);
    cout<<"\nsigned int:"<<sizeof(signed int);
    cout<<"\nunsigned int:"<<sizeof(unsigned int);
    cout<<"\nshort signed int:"<<sizeof(short signed);
    cout<<"\nshort unsigned int:"<<sizeof(short unsigned);
    cout<<"\nlong signed int:"<<sizeof(long signed int);
    cout<<"\nlong unsigned int:"<<sizeof(long unsigned);
    cout<<"\nfloat:"<<sizeof(float);
    cout<<"\ndouble:"<<sizeof(double);
    cout<<"\nlong double:"<<sizeof(long double);
    getch();
    return 0;
}