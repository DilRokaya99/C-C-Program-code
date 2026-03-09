#include<iostream>
#include<conio.h>
using namespace std;
class rectangle{
    int l,b;
    public:
    void SetData(int x,int y){
        l=x;
        b=y;
    }
    void area(){
        int l,b,area;
        cout<<"enter a length:";
        cin>>l;
        cout<<"enter breath:";
        cin>>b;
        area=l*b;
        cout<<area;
    }
};
int main(){
rectangle r1;
r1.area();
return 0;
}