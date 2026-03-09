#include<iostream>
#include<conio.h>
using namespace std;
class complex{
    int real,imaginary;
    public:
   complex (int r,int i){
    real=r;
    imaginary=i;
   }
   complex operator+(complex a1){
   return complex(real+a1.real,imaginary+a1.imaginary);
   }
   complex operator-(complex a1){
    return complex(real-a1.real,imaginary-a1.imaginary);
   }
   complex operator*(complex a1){
    return complex(real*a1.real,imaginary*a1.imaginary);
   }

   void show(){
    cout<<real<<"+"<<imaginary<<"i";
   }
};
int main(){
    int real1,imaginary1,real2,imaginary2;
    cout<<"enter the part of first real and imaginary complex nbr:";
    cin>>real1>>imaginary1;
    cout<<"enter the part of second real and imaginary complex nbr:";
    cin>>real2>>imaginary2;
    complex c1(real1,imaginary1);
    complex c2(real2,imaginary2);
    complex c3=c1+c2;
    complex diff=c1-c2;
    complex mult=c1*c2;
    cout<<"sum of complex nbr:";
    c1.show();
    cout<<"+";
    c2.show();
    cout<<"=";
    c3.show();
    cout<<"\ndiffernce complpex number:";
    c1.show();
    cout<<"-";
    c2.show();
    cout<<"=";
    diff.show();
    cout<<"\n product of complpex number:";
    c1.show();
    cout<<"*";
    c2.show();
    cout<<"=";
    mult.show();
    return 0;
}
