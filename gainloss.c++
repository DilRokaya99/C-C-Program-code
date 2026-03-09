#include <iostream>
#include <conio.h>
using namespace std;
int main(){
int amount,sp,cp;
cout<<"enter sale price :";
cin>>sp;
cout<<"enter the cost price:";
cin>>cp;
if(sp>cp){
    amount=sp-cp;
    cout<<" your profit amount is:"<<amount;
}
else if(cp>sp){
    amount=cp-sp;
    cout<<"your loss amount is"<<amount;
}
else{
    cout<<"your amount is neither gain nor loss";
}
return 0;
}