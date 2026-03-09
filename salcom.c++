#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    float sal,com;
    cout<<"enter employee sal:";
    cin>>sal;
    if(sal>=1000){
        com=sal*10/100;
        cout<<"employee commission increased by 10%\n employeecommission is:"<<com;
    }
    else{
        com=sal*5/100;
        cout<<"employee commission increased by 5%\n emplpoyeecommision is:"<<com;
    }
}