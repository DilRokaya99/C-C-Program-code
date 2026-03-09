#include <iostream>
#include<conio.h>
#include <vector>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

#define clrscr() cout << "\x1B[2J\x1B[H";
#define Delay(a) this_thread::sleep_for(chrono::milliseconds(a));

void print_with_delay(string s, int delay = 100, bool new_line = true) {
    for (int i = 0; i < s.length(); i++) {
        cout << s[i];
        Delay(delay);
    }
    if (new_line) {
        cout << endl;
    }
}

class Student {
private:
    string name;
    string branch;
    int phno;
    int rollNumber;
    int roomNumber;

public:
Student(){} 
    Student(string name, string branch, int phno, int rollNumber, int roomNumber)
        : name(name), branch(branch), phno(phno), rollNumber(rollNumber), roomNumber(roomNumber) {}

    string getName() const { return name; }
    string getBranch() const { return branch; }
    int getPhno() const { return phno; }
    int getRollNumber() const { return rollNumber; }
    int getRoomNumber() const { return roomNumber; }
    friend class HostelManager;
};

class HostelManager 
{
private:
    vector<Student> students;
    int totalRooms;
    int occupiedRooms;
    int availableRooms;

public:
 HostelManager(int totalRooms) : totalRooms(totalRooms), occupiedRooms(0), availableRooms(totalRooms) {
    }
    void loadData() {
        ifstream file("students.txt");
        if (file.is_open()) {
            Student student;
            while (file >> student.name >> student.rollNumber >> student.roomNumber >> student.phno >> student.branch) {
                students.push_back(student);
            }
            file.close();
        } else {
            cerr << "Error: Unable to load data from file." << endl;
    }
 }

    void saveData() {
        ofstream file("students.txt");
        if (file.is_open()) {
            for (const Student& student : students) {
                file << student.getName() << " " << student.getRollNumber() << " " << student.getRoomNumber()
                     << " " << student.getPhno() << " " << student.getBranch() << endl;
            }
            file.close();
        } else {
            cerr << "Error: Unable to save data to file." << endl;
        }
    }

    void addStudent(const Student& student) {
        students.push_back(student);
        saveData();
    }

    void editStudent(int rollNumber, const Student& updatedStudent) {
        for (Student& student : students) {
            if (student.getRollNumber() == rollNumber) {
                student = updatedStudent;
                saveData();
                return;
            }
        }
        cout << "Student not found with Roll Number: " << rollNumber << endl;
    }

    void deleteStudent(int rollNumber) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getRollNumber() == rollNumber) {
                students.erase(it);
                saveData();
                return;
            }
        }
        cout << "Student not found with Roll Number: " << rollNumber << endl;
    }

    void displayAllStudents() {
        if (students.empty()) {
            cout << "No students to display." << endl;
        } else {
            cout << "Student List:" << endl;
            for (const Student& student : students) {
                cout << "Name: " << student.getName() << endl;
                cout << "Roll Number: " << student.getRollNumber() << endl;
                cout << "Room Number: " << student.getRoomNumber() << endl;
                cout << "Phone Number: " << student.getPhno() << endl;
                cout << "Branch: " << student.getBranch() << endl;
                cout << "-------------------" << endl;
            }
        }
    }
    void SearchStudents(){
           clrscr();
            {
                  int rollNumber;
                    cout<<"\t\t\tEnter student roll number to search: ";
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
    }

                void Changeroom(){
                  clrscr();
                {
                    Student the_stu,stu;
                    int rollNumber,count_index=0;
                    cout<<"\t\t\tEnter student roll number to change room: ";
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
                    int old_room = students[count_index].roomNumber;
                    cout<<"\t\t\t\tENTER NEW ROOM = ";
                    cin>>students[count_index].roomNumber;
                    if(students[count_index].roomNumber >100){
                        print_with_delay("\t\t\t\tNOT ALLOWED GREATER THAN 100 ROOM",30);
                        goto found;
                    }
                    if(old_room == students[count_index].roomNumber){
                        print_with_delay("\n\t\t\t\tSAME ROOMNumber\n",10);
                        goto found;
                    }
                        int count=0;
                        for(Student &stu : students){
                        if(stu.roomNumber == students[count_index].roomNumber){
                        count++;
                        if(count >= 4){
                        print_with_delay("\t\t\t\tTHIS ROOM IS ALLREADY PACKED\n\t\t\t\t\tSO\n\t\t\t\tSHIFT THE NEXT ROOM",30);
                            goto found;
                        }
                    }
                    }
                     print_with_delay("\t\t\t\tSHIFTED Sucessfully.....",30);
                }
                 saveData();
    }

void calculateRoomStatistics() {
    int count=0;
    for (const Student& student : students) {
        count++; 
    }
    availableRooms = totalRooms - count;
    occupiedRooms = count;
}
    void displayRoom() {
        clrscr();
        calculateRoomStatistics();
        cout << "\t\t\tTotal Rooms: " << totalRooms << endl;
        cout << "\t\t\tOccupied Rooms: " << occupiedRooms << endl;
        cout << "\t\t\tAvailable Rooms: " << availableRooms << endl;
    }
    friend void hostel();
};

 void front(){  
            clrscr();
        cout<<"\t############################################################\n\n\t\t\t    WELCOME TO PROGRAM\n\n\t############################################################\n\n\t\t\t HOSTEL MANAGEMENT SYSTEM\n\t\t\t Created Date: 2023-09-07\n\n\n\n\n\n\n\n\n\n\nSUBMITED TO:\t\t\t\t\t\tSUBMITED BY:\n     Er.VEENUM DEVI\t\t\t\t\t     DIL BAHADUR ROKAYA\n\t\t\t\t\t\t\t     DIPENDRA SAUD\n\t\t\t\t\t\t\t     DHIRAJ KUMAR\n\t\t\t\t\t\t\t     CHAITANYA HARI";
        cout<<"\n\n\n\n  \t\t\tPress Enter To Open:-";
        }

 void hostel(){
    clrscr();
    int totalrooms=100;
    HostelManager manager(totalrooms);
    manager.loadData();    
    vector<Student> students;   
    do{
    int choice;
    cout<<endl;
    cout <<"\t\t\t-------------------------------------"<<endl;
    cout <<"\t\t\t----------ADD STUDENT DETAILS---------" << endl;
    print_with_delay("\t\t\t\t1. add new Student",10);
    print_with_delay("\t\t\t\t2. View All Students",10);
    print_with_delay("\t\t\t\t3. Search Student",10);
    print_with_delay("\t\t\t\t4. Edit Student",10);
    print_with_delay("\t\t\t\t5. Delete Student",10);
    print_with_delay("\t\t\t\t6. Change Room",10);
    print_with_delay("\t\t\t\t7. display Room",10);
    cout<<"\t\t\t\t8. Exit"<<endl;
        cout << "Enter your choice:- ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string name, branch;
                    int rollNumber, roomNumber, phno;

                    clrscr();
                    print_with_delay("Enter student name: ", 10, false);
                    cin.ignore();
                    getline(cin, name);
                    c:
                     print_with_delay("Enter student roll number: ", 10, false);
                    cin >> rollNumber;
                    for(auto i:manager.students){
                        if (i.getRollNumber()==rollNumber){
                            cout<<"this rollnumber is already exist\n";
                            goto c;
                        }
                    }

                    room:
                    print_with_delay("Enter student room number: ", 10, false);
                    cin >> roomNumber;
                    if(roomNumber>100){
                        cout<<"NOT ALLOWED GREATER THAN 100 ROOM"<<endl;
                        goto room;
                    }
                    int count =1;
                    for(auto i:manager.students){
                        if (i.getRoomNumber()==roomNumber){
                            count++;
                        }
                        if(count>4){
                            cout<<"this roomNumber is already has four student\n";
                            goto room;
                        }
                    }

                    print_with_delay("Enter student phone number: ", 10, false);
                    cin >> phno;
                    print_with_delay("Enter student branch: ", 10, false);
                    cin >> branch;

                    Student student(name, branch, phno, rollNumber, roomNumber);
                    manager.addStudent(student);

                    print_with_delay("Student added successfully!", 30);
                }
                break;

            case 2:
                clrscr();
                manager.displayAllStudents();
                break;
                
                case 3:
                manager.SearchStudents();
                break;

            case 4:
                {
                    int rollNumber;
                    clrscr();
                    print_with_delay("Enter student roll number to edit: ", 10, false);
                    cin >> rollNumber;

                    string name, branch;
                    int roomNumber, phno;

                    clrscr();
                    print_with_delay("Enter new student name: ", 10, false);
                    cin.ignore();
                    getline(cin, name);
                    print_with_delay("Enter new student room number: ", 10, false);
                    cin >> roomNumber;
                    print_with_delay("Enter new student phone number: ", 10, false);
                    cin >> phno;
                    print_with_delay("Enter new student branch: ", 10, false);
                    cin >> branch;

                    Student updatedStudent(name, branch, phno, rollNumber, roomNumber);
                    manager.editStudent(rollNumber, updatedStudent);

                    print_with_delay("Student edited successfully!", 30);
                }
                break;

            case 5:
                {
                    int rollNumber;
                    clrscr();
                    print_with_delay("Enter student roll number to delete: ", 10, false);
                    cin >> rollNumber;
                    manager.deleteStudent(rollNumber);
                }
                
                break;
                
                case 6:
                manager.Changeroom();
                break;

            case 7:
            manager.displayRoom();
            break;
            case 8:
                clrscr();
                print_with_delay("Exiting the program.", 50);
                manager.saveData();
                return;

            default:
                print_with_delay("Invalid choice. Please try again.", 30);
        }
    } while (true);

    return;
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
        print_with_delay("\t\t\t\tEnter choice:",60,false);
        cin>>ch;
        switch(ch) {
  case 1:
   hostel();
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
