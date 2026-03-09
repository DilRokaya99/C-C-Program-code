#include<iostream>
using namespace std;
class student{
    int roll,marks;
    char name[20];
    public:
    void getData(){
        int n;
        cout<<"enter no of student:";
        cin>>n;
        for(int i=0;i<n;i++){
        cout<<"enter name:",i+1;
        cin>>name;
        cout<<"enter roll no:",i+1;
        cin>>roll;
        cout<<"enter marks:",i+1;
        cin>>marks;
        }
    }
    void show(){
        int ch,n;
        for(int i=0;i<n;i++){
        if(ch==n){
            int per, total=0;
            total=total+marks;
            per=(total)/4;
            cout<<"name:"<<name<<endl<<"rollno:"<<roll<<endl<<"percentage:"<<per<<"%"<<endl;
        }
    }}
};
class result:public student{
    public:
    void input(){
        getData();
    }
        void output(){
            int n;
            for(int i=0;i<n;i++){
            show();
            }
        }
};
int main(){
    result r1;
    r1.input();
    r1.output();
    return 0;
}