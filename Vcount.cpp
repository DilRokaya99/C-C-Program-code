#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
    int v=0;
    char str[10],*p;
    cout<<"enter string:";
    cin>>str;
    p=str;
    while(*p!='\0'){
        if(*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u')
            v++;
        else
            p++;
        }
        cout<<"vowel="<<v<<endl;
        getch();
        return 0;
}