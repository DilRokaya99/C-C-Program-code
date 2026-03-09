#include<iostream>
#include<conio.h>
using namespace std;
class student{
    int roll,marks;
    char name[10];
    public:
    void input();
    void display();
};
void student::input(){
    int n;
    cout<<"no of student:";
    cin>>n;
    for(int i=0;i<n;i++){
    std::cout<<"\nstudent name:"<<i+1<<".";
    std::cin>>name;
    std::cout<<"\nstudent rollno:";
    std::cin>>roll;
    std::cout<<"\nstudent marks:";
    std::cin>>marks;
    }
}
void student::display(){
    int n;
    for(int i=0;i<n;i++){
    std::cout<<"\nstudent name:"<<name<<i+1<<".";
    std::cout<<"\nstudent rollno:"<<roll;
    std::cout<<"\nstudent marks:"<<marks;
}}
int main(){
    student n;
    n.input();
    n.display();
    getch();
    return 0;
}