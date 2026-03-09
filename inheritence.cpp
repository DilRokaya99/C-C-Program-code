#include<iostream>
using namespace std;
class person{
    int phno;
    char name[20];
    public:
    void getData(){
        cout<<"enter name:";
        cin>>name; 
        cout<<"enter phno:";    
        cin>>phno;
    }
    void show(){
        cout<<"name:"<<name<<endl<<"phno:"<<phno<<endl;
    }
};
class student:public person{
    int roll;
    char name[10];
    public:
    void setData(){
        getData();
        cout<<"enter name:";
        cin>>name;
        cout<<"enter roll no:";
        cin>>roll;
    }
    void write(){
        show();
        cout<<"name"<<name<<endl<<"rollno:"<<roll;
    }
};
class result:public student{
int m[5];
public:
void read(){
    cout<<"\nenter 5 sub marks:";
    for(int i=0;i<5;i++){
        cin>>m[5];
    }
}
void cal(){
int per,total=0;
for(int i=0;i<5;i++){
    total=total+m[i];
per=(total)/4;
}
cout<<"percentage:"<<per<<"%";
}
};
int main(){
    result s1;
    s1.setData();
    s1.write();
    s1.read();
    s1.cal();
    return 0;
}