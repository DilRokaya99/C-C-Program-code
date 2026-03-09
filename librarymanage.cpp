#include <iostream>
#include<conio.h>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<fstream>
#include<stdio.h>
using namespace std;

class book{
    char bno[10];
    char bname[50];
    char aname[30];
    public:
    void createbook(){
	cout<<"\nENTER BOOK ENTRY...";
	cout<<"\nENTER THE BOOK NUMBER:";
	cin>>bno;
	cout<<"\nENTER BOOK NAME:";
	gets(bname);
	cout<<"\nTHE AUTHOR's NAME:";
	gets(aname);
	cout<<"\n\n\nBOOK CREATED....";
     }
     void showbook(){
	cout<<"\nBOOK NUMBER:"<<bno;
	cout<<"\nBOOK NAME:";
	puts(bname);
	cout<<"\nAUTHOR'S NAME: ";
	puts(aname);
     }
     void modifybook(){
    cout<<"\nENTER BOOK:"<<bno;
    cout<<"\nMODIFY BOOK NAME:";
    gets(bname);
    cout<<"\nMODIFY AUTHOR'S NAME:";
    gets(aname);
     }
     char* retbno(){
	return bno;
     }
     void report(){
	cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
     }
};//class a

class student{
    char admno[10];
    char name[30];
    char stbno[30];
    int token;
    public:
    void createstudent(){
	cout<<"\nNEW STUDENT ENTRY";
	cout<<"\nENTER THE ADMISSION NUMBER:";
	cin>>admno;
	cout<<"\nENTER THE STUDENT NAME:";
	gets(name);
	token=0;
	stbno[0]='/0';
	cout<<"\n\nSTUDENT RECORD CREATED";
    }
    void showstudent(){
	cout<<"\nAddmission Number:"<<admno;
	cout<<"\nStudennt Name:";
	puts(name);
	cout<<"\nNumber of Book Issued:"<<token;
	if(token==1){
	    cout<<"\nBOOK NUMBER"<<stbno;
	}
    }
    void modifystudent(){
	cout<<"\nAdmission number :"<<admno;
	cout<<"\nModify Student Name :";
	gets(name);
    }
    char* retadmno(){
	return admno;
    }
    char* retstbno(){
	return stbno;
}
    int rettoken(){
	return token;
    }
    void addtoken(){
	token=1;
    }
    void resettoken(){
	token=0;
    }
    void getsbno(char t[]){
	strcpy(stbno,t);
    }
    void report(){
	cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<token<<endl;
    }
};//class endd
fstream fp,fp1;
book bk;///book write file function
student st;
void writebook(){
    char ch;
    fp.open("book.dat",ios::out|ios::app);
    do{
	bk.createbook();
	fp.write((char*)&bk,sizeof(book));
	cout<<"\n\ndo you want to add more record...(y/n?):";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}
void writestudent(){
    char ch;
    fp.open("student.dat",ios::out|ios::app);
    do{
clrscr();
	st.createstudent();
	fp.write((char*)&st,sizeof(student));
	cout<<"\n\ndo you want to add more record...(y/n?):";
	cin>>ch;
    }while(ch=='y'||ch=='Y');
    fp.close();
}

void displayspb(char n[]){
    cout<<"\nBook details\n";
    int flag=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char *)&bk,sizeof(book))){
	if(strcmpi(bk.retbno(),n)==0){
	    st.showstudent();
	    flag=1;
	}
    }
    fp.close();
    if(flag==0){
	cout<<"\nBook dont exist";
    }
    getch();
}

void displaysps(char n[]){
    cout<<"\nBStudent details\n";
    int flag=0;
    fp.open("student.dat",ios::in);
    while(fp.read((char *)&st,sizeof(student))){
	if(strcmpi(st.retadmno(),n)==0){
	    st.showstudent();
	    flag=1;
	}
    }
    fp.close();
    if(flag==0){
	cout<<"\nBook dont exist";

    }
    getch();
}

void modifybook(){
    char n[6];
    int found=0;
clrscr();
    cout<<"\n\nMODIFY BOOK RECORD...";
    cout<<"\nENTER BOOK NUMBER";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(book)) && found==0){
	if(strcmpi(bk.retbno(),n)==0){
	    bk.showbook();
	    cout<<"ENTER  THE NEW DETAIL OF BOOK:"<<endl;
	    bk.modifybook();
	    int pos=-1*sizeof(bk);
	    fp.seekp(pos,ios::cur);
	    fp.write((char *)&bk,sizeof(book));
	    cout<<"\n\n\t RECORD UPDATED";
	    found=1;;
	}
    }
    fp.close();
    if(found==0){
	cout<<"\n\nRECORD NOT FOUND";
    }
    getch();
}

void modifystudent(){
    char n[6];
    int found=0;
    cout<<"\n\nMODIFY STUDENT RECORD...";
    cout<<"\nENTER ADMISSION NUMBER:";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student)) &&  found==0){
	if(strcmpi(st.retadmno(),n)==0){
	    st.showstudent();
	    cout<<"ENTER  THE NEW DETAIL OF STUDENT:";
	    st.modifystudent();
	    int pos=-1*sizeof(st);
	    fp.seekp(pos,ios::cur);
	    fp.write((char *)&st,sizeof(student));
	    cout<<"\n\n\t RECORD UPDATED";
	    found=1;
	}
    }
    fp.close();
    if(found==0){
	cout<<"\n\nRECORD NOT FOUND";
    }
    getch();
}

void deletestudent(){
    char n[6];
    int flag=0;
    cout<<"\n\n\nDELETE STUDNET...";
    cout<<"\n\nEnter the admission no.:";
    cin>>n;
    fp.open("student.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&st,sizeof(student))){
	if(strcmpi(st.retadmno(),n)!=0){
	    fp2.write((char*)&st,sizeof(student));
	}
	else{
	    flag=1;
	}
    }
    fp2.close();
    fp.close();
    remove("student.dat");
    rename("temp.dat","student.dat");
    if(flag==1){
	cout<<"\n\n\tRecord deleted..";
    }
    else{
	cout<<"\n\nrecord not found";
    }
    getch();
}
void deletebook(){
    char n[6];
    int flag=0;
    cout<<"\n\n\nDELETE BOOK...";
    cout<<"\n\nEnter the book no.:";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(book))){
	if(strcmpi(bk.retbno(),n)!=0){
	    fp2.write((char*)&bk,sizeof(book));
	}
	else{
	    flag=1;
	}
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    if(flag==1){
	cout<<"\n\n\tRecord deleted..";
    }
    else{
	cout<<"\n\nrecord not found";
    }
    getch();
}

void displayalls(){
    clrscr();
    fp.open("student.dat",ios::in);
    if(!fp){
	cout<<"file not open";
	getch();
	return;
    }
    cout<<"\n\n\tStudent list\n\n";
    cout<<"===========================================================\n";
    cout<<"\tAdmission no."<<setw(10)<<"Name"<<setw(20)<<"Book issued\n";
    cout<<"===========================================================\n";
    while(fp.read((char*)&st,sizeof(student))){
	st.report();
    }
    fp.close();
    getch();
}
void displayallb(){
    clrscr();
    fp.open("book.dat",ios::in);
    if(!fp)
    {
	cout<<"file not open";
	getch();
	return;
    }
    cout<<"\n\n\tBook list\n\n";
    cout<<"=======================================================\n";
    cout<<"Book number"<<setw(20)<<"Book Name"<<setw(25)<<"Author\n";
    cout<<"=======================================================\n";
    while(fp.read((char*)&bk,sizeof(book))){
	bk.report();
    }
    fp.close();
    getch();
}

void bookissue(){
    char sn[6],bn[6];
    int found=0,flag=0;
    clrscr();
    cout<<"\n\nBook issue...";
    cout<<"\n\n\t Enter admission number of student:";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))  &&found==0){
	if (strcmpi(st.retadmno(),sn)==0){
	    found=1;
	    if(st.rettoken()==0){
		cout<<"\n\nEnter the book number";
		cin>>bn;
	      while(fp1.read((char*)&bk,sizeof(book))  &&  flag==0)  {
		  if(strcmpi(bk.retbno(),bn)==0){
		      flag=1;
		      st.addtoken();
		      st.getsbno(bk.retbno());
		      int pos=-1*sizeof(st);
		      fp.seekg(pos,ios::cur);
		      fp.write((char*)&st,sizeof(student));
		      cout<<"\n\n\tBook Issued Successfully\n\nPlease Note:Write the book issued date in back side of your book and return book within 15 days,fine RS.1 for each days";
		  }
	      }
	      if(flag==0){
		  cout<<"Book does not exit";
	      }
	    }
	    else{
		cout<<"You have not return the last book";
	    }
	}
    }
    if(found==0){
		  cout<<"studnet record not exit";
	      }
	      getch();
	      fp.close();
	      fp1.close();
}
void bookdeposit(){
    char sn[6],bn[6];
    int found=0,flag=0,day,fine;
    clrscr();
    cout<<"\n\nBook Deposit...";
    cout<<"\n\n\t Enter admission number of student:";
    cin>>sn;
    fp.open("student.dat",ios::in|ios::out);
    fp1.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&st,sizeof(student))  &&  found==0){
	if (strcmpi(st.retadmno(),sn)==0){
	    found=1;
	    if(st.rettoken()==1){

	      while(fp1.read((char*)&bk,sizeof(book))  &&  flag==0)  {
		  if (strcmpi(bk.retbno(),st.retstbno())==0){
		      flag=1;
		      bk.showbook();

		      cout<<"\n\nBook Deposited in no. of days:"<<fine<<endl;
		      cout<<"enter the number of day: ";
		      cin>>day;
		      if(day>15){
			  fine=(day-15)*1;
			  cout<<"\n\n fine is deposited Rs."<<fine;
		      }
		      st.resettoken();
		      int pos=-1*sizeof(st);
		      fp.seekg(pos,ios::cur);
		      fp.write((char*)&st,sizeof(student));
		      cout<<"\n\n\tBook Deposited Successfully";
		  }
	      }
	      if(flag==0){
		  cout<<"Book does not exit";
	      }
	    }
	    else{
		cout<<"No Book Is Issued..";
	    }
	}
    }
    if(found==0){
		  cout<<"student record not exit";
	      }
	      getch();
	      fp.close();
	      fp1.close();
}

void start() {
clrscr();
gotoxy(35,11);
    cout << "LIBRARY";
gotoxy(35,14);
cout<<"MANAGEMENT";
gotoxy(35,17);
cout<<"SYSTEM";
    cout<<"\nBY GURNOOR\n BIRAZAD\n DAMAN\n JAIDEEP";
getch();
}
void adminmenu(){
    int ch2;
    cout<<"\n\tADMINISTRATOR  MENU";
    cout<<"\n\t1.CREATE STUDENT RECORD";
    cout<<"\n\t2.DISPLAY ALL THE STUDENT RECORD";
    cout<<"\n\t3.DISPLAY SPECIFIC STUDENT RECORD";
    cout<<"\n\t4.MODIFY STUDENT RECORD";
    cout<<"\n\t5.DELETE STUDENT RECORD";
    cout<<"\n\t6.CREATE BOOK";
    cout<<"\n\t7.DISPLAY ALL BOOKS";
    cout<<"\n\t8.DISPLAY ALL SPECIFIC BOOK";
    cout<<"\n\t9.MODIFY BOOK RECORD";
    cout<<"\n\t10.DELETE BOOK RECORD";
    cout<<"\n\t11.BACK TO MAIN MENU";
    cout<<"\n\tENTER YOUR CHOICE:";
    cin>>ch2;
    switch(ch2){
	case 1:
	writestudent();
	break;
	case 2:
	displayalls();
	break;
	case 3:
	char num[6];
	clrscr();
	cout<<"\n\nPlease enter the admission number:";
	cin>>num;
	displaysps(num);
	break;
	case 4:
	modifystudent();
	break;
	case 5:
	deletestudent();
	break;
	case 6:
	writebook();
	break;
	case 7:
	displayallb();
	break;
	case 8:
	{
	    char num[6];
	    cout<<"\n\n\tPlease Enter The Book NO.";
	    cin>>num;
	    displayspb(num);
	break;
	}
	case 9:
       modifybook();
	break;
	case 10:
	deletebook();
	break;
	case 11:
	return;

	default:
	cout<<"default option";
    }
    adminmenu();
   }

  void main() {
    char ch;
    start();
    do{
    clrscr();
	cout<<"\n\n\nMAIN MENU";
	cout<<"\n\n\t1.BOOK ISSUE";
	cout<<"\n\n\t2.BOOK DEPOSIT";
	cout<<"\n\n\t3.ADMINISTRATOR MENU";
	cout<<"\n\n\t4.THANKU :)";
	cout<<"\nENTER YOUR CHOICE(1-4):";
	ch=getche();
	switch(ch){
	    case '1':
	    bookissue();
	    break;
	     case '2':
	    bookdeposit();
	    break;
	     case '3':
	    adminmenu();
	    break;
	     case '4':
	    exit(0);
	    break;
	    default:
	    cout<<"Invalid Choice";
	}
    }while(ch!=4);

    getch();
}