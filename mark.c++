#include <iostream>
#include <conio.h>
using namespace std;
int main(){
float a[10];
int i;
cout<<"enter the 10 student:";
for(i=1;i<10;i++){
cin>>a[i];
cout<<i<<"."<<"student"<<"\n";
}
int count=0,fail=0;
for(i=0;i<10;i++){
    if(a[i]>35){
        count++;
    }
    else{
        fail++;
    }
}
cout<<"passed student are:"<<count<<"\n";
cout<<"failed student are:"<<fail;
return 0;
}