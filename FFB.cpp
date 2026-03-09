#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void login(){
    char username[20];
    char password[30];
        l:
        cout<<"\nenter your username:";
        cin>>username;
        if(strcmp(username,"dilrokka")==0){
            cout<<"sucessfull";
        }
        else{
            cout<<"\ndoes not exist your username";
            cout<<"\nplease try agian";
            goto l;
        }
        k:
        cout<<"\nenter your password:";
        cin>>password;
        if(strcmp(password,"dilli")==0){
        cout<<"sucessfull...";
        }
        else{
            cout<<"\nwrong your password";
            cout<<"\nplease try agian";
            goto k;
        }
    }
void create(){
        int c,n;
        char password[20];
        char name[10];
        char code[20];
        cout<<"\nenter first name:";
        cin>>name;
        cout<<"\nenter last name:";
        cin>>name;
        cout<<"enter your DOB:";
        cin>>n;
        cout<<"\n1.male\n2.female\n3.other";
        cout<<"\nenter your gender:";
        cin>>c;
        if(c=='1','2','3'){
            cout<<"\nsucess";
        }
        else{
            cout<<"\ninvalid choice";
        }
        n:
        cout<<"\nenter your phone no:";
        cin>>n;
        cout<<"\nenter your OTP code:";
        cin>>code;
        if(strcmp(code,"1234")==0){
            cout<<"sucess";
        }
        else{
            cout<<"\nincorrect your otp code";
            cout<<"\nplease try agian";
            goto n;
        }
        cout<<"\nenter password:";
        cin>>password;
        cout<<"enter confirm password:";
        cin>>password;
    }
void forget(){
    int n;
    char code[20];
    char password[20];
     cout<<"\nenter your ph nbr:";
        cin>>n;
        m:
        cout<<"\nenter your OTP code:";
        cin>>code;
        if(strcmp(code,"342")==0){
            cout<<"sucess";
        }
        else{
            cout<<"wrong otp code";
            cout<<"\nplease try agian";
            goto m;
        }
        cout<<"\nenter your new password:";
        cin>>password;
        cout<<"\nconfirm password:";
        cin>>password;
}
int main(){
    int ch,n;
        cout<<"\t\t.........FACEBOOK........";
    cout<<"\n\nenter any nbr:";
    cin>>n;
    do{
    cout<<"1.login your page:\n2.forget password:\n3.create a new acccount:\n4.EXIT";
    cout<<"\nenter your choice:";
    cin>>ch;
    switch(ch){
        case 1:
        login();
        break;
        case 2:
        forget();
        break;
        case 3:
        create();
        break;
        case 4:
       goto end;
       default:
       cout<<"invalid choice:";
    }
    }while(1);
    end:
    return 0;
}
