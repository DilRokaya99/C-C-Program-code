#include<iostream>
#include<conio.h>
using namespace std;
class bank{
    private:
    int total;
    string id;
    struct person{
        string name,ID,address;
        int contact,cash;
    }person[100];
    public:
    bank(){
        total=0;
    }
    void choice();
    void perData();
    void show();
    void update();
    void search();
    void transection();
    void del();
};  
    int main(){
        bank b;
      int ch;
    do{
    cout<<"\t\t....BANKING SYSTEM..."<<endl;
    cout<<"\nPRESS...!!"<<endl;
    cout<<"1.create new account:"<<endl;
    cout<<"2.view costumer list:"<<endl;
    cout<<"3.update information of existing account:"<<endl;
    cout<<"4.check the detail of an existing account:"<<endl;
    cout<<"5.for transectionL"<<endl;
    cout<<"6.remove existing account:"<<endl;
    cout<<"7.EXIT"<<endl;   
    cout<<"\nenter any choice:";
    cin>>ch; 
    switch(ch){
        case 1:
        b.perData();
        break;
        case 2:
        b.show();
        break;
        case 3:
        b.update();
        break;
        case 4:
        b.search();
        break;
        case 5:
        b.transection();
        break;
        case 6:
        b.del();
        break;
        case 7:
        goto end;
        default:
        cout<<"invlaid choice:";
    }
    }while(1);
    end:
    return 0;
    }
    void bank::perData(){
        int i;
        cout<<"enter data of person:"<<total+1<<endl;
        cout<<"enter name:";
        cin>>person[i].name;
        cout<<"enter id:";
        cin>>person[i].ID;
        cout<<"enter address:";
        cin>>person[i].address;
        cout<<"enter contact:";
        cin>>person[i].contact;
        cout<<"enter cash:";
        cin>>person[i].cash;
        total++;
    }
void bank::show(){
    for(int i=0;i<total;i++){
        cout<<"Data person:"<<i+1<<endl;
        cout<<"Name:"<<person[i].name<<endl;
        cout<<"id:"<<person[i].ID<<endl;
        cout<<"address:"<<person[i].address<<endl;
        cout<<"contact:"<<person[i].contact<<endl;
        cout<<"cash:"<<person[i].cash<<endl;
        cout<<"enter new data:";
    }}
void bank::update(){
    cout<<"enter id of student those data you want to update:";
    cin>>id;
    for(int i=0;i<total;i++){
        if(id==person[i].ID){
        cout<<"previous data"<<endl;
        cout<<"Data person:"<<i+1<<endl;
        cout<<"Name:"<<person[i].name<<endl;
        cout<<"id:"<<person[i].ID<<endl;
        cout<<"address:"<<person[i].address<<endl;
        cout<<"contact:"<<person[i].contact<<endl;
        cout<<"cash:"<<person[i].cash<<endl;
        cout<<"enter new data:";
        break;
        }
        if(i==total-1){
            cout<<"no such record found"<<endl;
        }
    }
}
void bank::search(){
    cout<<"enter id of student those data you want to search:";
    cin>>id;
    for(int i=0;i<total;i++){
    if(id==person[i].ID){
        cout<<"Data person:"<<i+1<<endl;
        cout<<"Name:"<<person[i].name<<endl;
        cout<<"id:"<<person[i].ID<<endl;
        cout<<"address:"<<person[i].address<<endl;
        cout<<"contact:"<<person[i].contact<<endl;
        cout<<"cash:"<<person[i].cash<<endl;
        break;
    }
     if(i==total-1){
        cout<<"no such record found"<<endl;
     }
    }
}
void bank::transection(){
    int ch;
    char cash;
    cout<<"enter id of student those data you want to transection:";
    cin>>id;
    for(int i=0;i<total;i++){
        if(id==person[i].ID){
        cout<<"Name:"<<person[i].name<<endl;
        cout<<"id:"<<person[i].ID<<endl;
        cout<<"address:"<<person[i].address<<endl;
        cout<<"contact:"<<person[i].contact<<endl;
        cout<<"existing cash:"<<person[i].cash<<endl;
        cout<<"press 1 to deposit:"<<endl;
        cout<<"press 2 to withdraw:"<<endl;
        cout<<"enter any choice:";
        cin>>ch;
        switch(ch){
            case 1:
            cout<<"how much cash do you want to deposit?"<<endl;
            cin>>cash;
            person[i].cash=person[i].cash+cash;
            cout<<"your new cash is:"<<person[i].cash<<endl;
            break;
            case 2:
            cout<<"how much do you want to withdraw?"<<endl;
            cin>>cash;
            if(cash>person[i].cash){
            cout<<"your existing cash is just:"<<person[i].cash<<endl;
            }
            else{
            person[i].cash=person[i].cash-cash;
            cout<<"your new cash is:"<<person[i].cash<<endl;
            }
            break;
            default:
            cout<<"invalid choice";
        }
        break;
    }
    if(i==total-1){
        cout<<"no such record found"<<endl;
    }
   }
}
void bank::del(){
    char ch;
    cout<<"press 1 to remove specific record:"<<endl;
    cout<<"press 2 to remove full record:";
    cout<<"enter choice:";
    cin>>ch;
    switch(ch){
        case 1:
        cout<<"enter id of student those data you want to delete";
        cin>>id;
        for(int i=0;i<total;i++){
            if(id==person[i].ID){
            for(int j=i;j<total;j++){
            person[i].name=person[i+1].name;
            person[i].ID=person[i+1].ID;
            person[i].address=person[i+1].address;
            person[i].contact=person[i+1].contact;
            person[i].cash=person[i+1].cash;  
                total--;
                cout<<"your required data is deleted"<<endl;
                break;
                }
            }
             if(i==total-1){
        cout<<"no such record found"<<endl;
    }
        }
        break;
        case 2:
        total=0;
        cout<<"All record is deleted";
        break;
    }
}