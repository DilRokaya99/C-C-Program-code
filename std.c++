#include<iostream>
#include<conio.h>
using namespace std;
struct student{
    int id,rollno;
    char name[20];
    struct address{
        char country[10];
        char district[10];
        char village[20];
    }a;
}s[10];
int main(){
    int n,i;
    cout<<"enter a no of student:";
    cin>>n;
    for(i=0;i<n;i++){
    cout<<"\nenter student name:",i+1;
    cin>>s[i].name;
    cout<<"\nenter student rollno:",i+1;
    cin>>s[i].rollno;
    cout<<"\nenter student id:",i+1;
    cin>>s[i].id;
    cout<<"\nenter student country name:",i+1;
    cin>>s[i].a.country;
    cout<<"\nenter district name:",i+1;
    cin>>s[i].a.district;
    cout<<"\nenter village name:",i+1;
    cin>>s[i].a.village;
    }
    cout<<"\ntotal student detail record:\n\n";
    for(i=0;i<n;i++){
        cout<<"\n"<<s[i].name;
        cout<<"\n"<<s[i].rollno;
        cout<<"\n"<<s[i].id;
        cout<<"\n"<<s[i].a.country;
        cout<<"\n"<<s[i].a.district;
        cout<<"\n"<<s[i].a.village;
    }
    getch;
    }