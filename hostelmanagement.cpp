//does not using class and object
#include <iostream>
#include<conio.h>
#include <vector>
#include <string>
#include<fstream>
#include<thread>
#include<chrono>
#define clrscr() cout << "\x1B[2J\x1B[H";
#define Delay(a) this_thread::sleep_for(chrono::milliseconds(a));
using namespace std;
struct Student {
    string name;
    string branch;
    int phno;
    int rollNumber;
    int roomNumber;
};
void print_with_delay(string s,int delay = 100,bool new_line = true){
    for(int i=0;i<s.length();i++){
        cout<<s[i];
        Delay(delay);
    }
    if(new_line){
        cout<<endl;
    }
}

void saveData(const vector<Student>& students) {
    ofstream file("students.txt");
    if (file.is_open()) {
        for (const Student& student : students) {
            file << student.name << " " << student.rollNumber <<" "<<student.roomNumber <<" "<<student.phno <<" "<<student.branch << " " << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to save data to file." << endl;
    }
}

void loadData(vector<Student>& students) {
    ifstream file("students.txt");
    if (file.is_open()) {
        Student student;
        while (file >> student.name >> student.rollNumber >>student.roomNumber >>student.phno >> student.branch) {
            students.push_back(student);
        }
        file.close();
    } else {
        cerr << "Error: Unable to load data from file." << endl;
    }
}

void editStudent(vector<Student>& students) {
    clrscr();
    int rollNumber;
    print_with_delay("\t\t\tEnter RollNUmber of  the student you want to edit: ",30,false);
    cin >> rollNumber;

    if (rollNumber >= 0 && rollNumber < students.size()) {
        Student& student = students[rollNumber];
        cout << "\t\t\t\tEditing student at rollNumber: " << rollNumber << endl;
        print_with_delay("\t\t\t\tEnter new student name: ",40,false);
        cin >> student.name;
        print_with_delay("\t\t\t\tEnter new student rollnumber: ",40,false);
        cin >> student.rollNumber;
        aa:
        print_with_delay("\n\t\t\t\tEnter new student roomnumber: ",40,false);
        cin >> student.roomNumber;
        if(student.roomNumber>10){
        print_with_delay("\n\t\t\t\tNO ROOM GREATER THAN 10 IS AVAILABLE",40);
        goto aa;
        }
        int count=0;
        for(Student &stu : students){
            if(stu.roomNumber == student.roomNumber){
                count++;
                if(count >= 2){
                   print_with_delay("\t\t\t\tTHIS ROOM IS ALLREADY EXIST",30);
                   print_with_delay("\t\t\t\t\tSO \n \t\t\t\tSHIFT THE NEXT ROOM",30,false);
                    goto aa;
                }
            }
        }
        print_with_delay("\t\t\t\tSHIFTED SUCESSFULLY...",30,false);
        print_with_delay("\n\t\t\t\tEnter new student phone number:",40,false);
        cin >> student.phno;
        print_with_delay("\t\t\t\tEnter new student branch:",40,false);
        cin >> student.branch;
        print_with_delay("\t\t\t....Student edited successfully!...",30,false);
    } else {
        cout << "\t\t\tInvalid rollNumber. No student found at rollNumber " << rollNumber << endl;
    }
}


void deleteStudent(vector<Student>& students) {
    clrscr();
    int rollNumber;
    print_with_delay("\t\t\tEnter the rollNumber of the student you want to delete: ",40,false);
    cin >> rollNumber;
    if (rollNumber >= 0 && rollNumber < students.size()) {
        students.erase(students.begin() + rollNumber);
        print_with_delay("\t\t\t\tStudent deleted successfully!",30,false);
    } else {
        cout << "\t\t\tInvalid rollNumber. No student found at rollNumber " << rollNumber << endl;
    }
}
    void hostelmanager(){
        clrscr();
    int totalRooms = 10;     
    vector<Student> students; 
    loadData(students);  
    do{
    int c;
    cout<<endl;
    cout <<"\t\t\t-------------------------------------"<<endl;
    cout <<"\t\t\t----------ADD STUDENT DETAIL---------" << endl;
    print_with_delay("\t\t\t\t1. add new Student",40);
    print_with_delay("\t\t\t\t2. View All Students",40);
    print_with_delay("\t\t\t\t3. Search Student",40);
    print_with_delay("\t\t\t\t4. Edit Student",40);
    print_with_delay("\t\t\t\t5. Delete Student",40);
    print_with_delay("\t\t\t\t6. Change Room",40);
    cout<<"\t\t\t\t7. Exit"<<endl;
    print_with_delay("\t\t\t\tEnter your choice: ",40,false);
    cin>>c;
    switch(c){
          case 1: 
                {
                    clrscr();
                    Student student,stu;
                    print_with_delay("\t\t\tEnter student name: ",40,false);
                    cin.ignore();
                    getline(cin, student.name);
                    print_with_delay("\t\t\tEnter student roll number: ",40,false);
                    cin >> student.rollNumber;
                    
                    int selected = 1;
                    for(Student &stu : students){
                        if(stu.roomNumber == selected){
                            selected++;
                        }
                    }
                    if (selected<=10) {
                        student.roomNumber = selected;
                        cout << "\t\t\tStudent allocated Room Number: " << selected << endl;
            
                    } else{
                        print_with_delay("\t\t\tNo available rooms. Student cannot be allocated a room.",20,false);
                        return;
                    }
                    
                    cout <<"\t\t\tenter student phone number:";
                    cin >> student.phno;
                    cout <<"\t\t\tenter student branch:";
                    cin >>student.branch;
                    students.push_back(student);
                    saveData(students); 
                  print_with_delay("\t\t\t...Student added successfully!...",30);
                }
                break;

            case 2: 
            clrscr();
                if (students.empty()) {
                    print_with_delay("\t\t\tNo students to display.",30);
        
                } else {
                    print_with_delay("\t\t\t\t...Student List.....",50);
                    for (const Student& student : students) {
                        cout << "Name: " << student.name;
                        cout << " Roll Number:" << student.rollNumber;
                        cout << " Room Number:" <<student.roomNumber;
                        cout << " phone Number:" <<student.phno;
                        cout << " branch:"       <<student.branch<<endl;
                    }
                }
                break;

            case 3: 
            clrscr();
            {
                  int rollNumber;
                    print_with_delay("\t\t\tEnter student roll number to search: ",50,false);
                    cin >> rollNumber;
        

                    bool found = false;
                    for (const Student& student : students) {
                        if (student.rollNumber == rollNumber) {
                            print_with_delay("\t\t\tSTUDENT FOUND:",30);
                
                            cout << "\t\t\t\t\tName:" << student.name<<endl;
                
                            cout << "\t\t\t\t\tRoll Number:" <<student.rollNumber<<endl;
                
                            cout << "\t\t\t\t\tRoom Number:" <<student.roomNumber<<endl;
                
                            cout << "\t\t\t\t\tphone Number:" <<student.phno<<endl;
                
                            cout << "\t\t\t\t\tbranch:" <<student.branch<<endl;   
                                        
                            found = true;
                            break;
                        }
                    }

                    if (!found) {
                        print_with_delay("\t\t\t\tSTUDENT NOT FOUND.",30);
            
                    }
                }
                break;

            case 4: 
                editStudent(students);
                break;

            case 5: 
                deleteStudent(students);
                break;
                  case 6: 
                  clrscr();
                {
                    Student the_stu,stu;
                    int rollNumber,count_index=0;
                    print_with_delay("\t\t\tEnter student roll number to change room: ",50,false);
                    cin >> rollNumber;
                    for(Student &the_stu : students){
                        if(the_stu.rollNumber == rollNumber){
                            goto found;
                            break;
                        }
                        count_index++;
                    }
                    return;
                    found:
                    cout<<"\t\t\t\tENTER NEW ROOM = ";
                    cin>>students[count_index].roomNumber;
                    if(students[count_index].roomNumber >10){
                        print_with_delay("NOT ALLOWED GREATER THAN 10 ROOM",30);
                        goto found;
                    }
                        int count=0;
                        for(Student &stu : students){
                        if(stu.roomNumber == students[count_index].roomNumber){
                        count++;
                        if(count >= 2){
                        print_with_delay("\t\t\t\tTHIS ROOM IS ALLREADY PACK\n\t\t\t\t\tSO\n\t\t\t\tSHIFT THE NEXT ROOM",30);
                            goto found;
                        }
                    }
                    }
                     print_with_delay("\t\t\t\tSHIFTED Sucessfully.....",30);
                }
                break;
            
            case 7:
                print_with_delay("\t\t\t\tExiting the program.",50);
                saveData(students); 
                goto end;
            default:
                print_with_delay("\t\tInvalid choice. Please try again.",30);
        }
        }while(1);
        end:
        return ;
        }
        void front(){  
            clrscr();
        cout<<"\t############################################################\n\n\t\t\t    WELCOME TO PROGRAM\n\n\t############################################################\n\n\t\t\t HOSTEL MANAGEMENT SYSTEM\n\t\t\t Created Date: 2023-09-07\n\n\n\n\n\n\n\n\n\n\nSUBMITED TO:\t\t\t\t\t\tSUBMITED BY:\n     Er.VEENUM SHARMA\t\t\t\t\t     DIL BAHADUR ROKAYA\n\t\t\t\t\t\t\t     DIPENDRA SAUD\n\t\t\t\t\t\t\t     DHIRAJ KUMAR\n\t\t\t\t\t\t\t     CHETANNA HARI";
        }
int main() { 
    clrscr();
    front();
    char ch;
     ch=getch();
    while (true) {
        clrscr();
        int ch;
        cout<<endl<<endl;
        cout<<"\t\t\t*********************************************"<<endl;
        print_with_delay("\t\t\t\t HOSTEL MANAGEMENT SYSYTEM\t",60);
        cout<<"\t\t\t*********************************************"<<endl<<endl;
        print_with_delay("\t\t\t\t1.STUDENT MANAGEMENT SYSTEM",40);
        cout<<"\t\t\t\t2.EXIT"<<endl;
        print_with_delay("\t\t\t\tenter choice:",60,false);
        cin>>ch;
        switch(ch) {
  case 1:
   hostelmanager();
   break;
   case 2:
   print_with_delay("\t\t\t\tExiting the program.",50);
   goto end;
   break;
  default:
  print_with_delay("\t\tInvalid choice. Please try again.",40);
  }
    }
  end:
  return 0;
}
