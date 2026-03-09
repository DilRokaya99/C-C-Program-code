#include<iostream>
#include<conio.h>
using namespace std;
class value{
    private:
    int val;
    public:
    value(int a){
        val=a;
}
void show(){
    cout<<val;
}
int operator==(value obj){
    if(val==obj.val){
        return 1;
    }
    return 0;
}
};
int main(){
value v1(20);
value v2(20);
if(v1==v2){
    cout<<"v1 is equal to v2";
}
else{
    cout<<"v1 is not eqal to v2";
}
    return 0;
    }