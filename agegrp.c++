#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int s[10],i;
    cout<<"enter age of 10 students:";
    for(i=0;i<10;i++){
        cin>>s[i];
        cout<<i<<"student age is:"<<s[i]<<"\n";
    }
    int count=0;
    for(i=0;i<10;i++){
        if(s[i]>=20 && s[i]<=30){
            count++;
        }
    }
    cout<<"the students in the age group of 20 to 30:"<<count;
} 