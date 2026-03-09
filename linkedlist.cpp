#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int value,data;
    node *ptr;
};
node *hptr=0,*tmptr;
void insert_element(node *&hptr){
    node *nptr = new node;
    int n;
    cout<<"no of element:";
    cin>>n;
    for(int i=0;i<n;i++){
    cout<<"value:-";
    cin>>nptr->value;
    nptr->ptr = 0;
    if(hptr == 0){
        hptr=tmptr=nptr;
    }
    else{
        tmptr->ptr=nptr;
        tmptr=nptr;
    }}
}
void show_element(node* &hptr){
    node *tmp = 0;
    do{
        if(tmp==0){
            tmp=hptr;
        }
        else{
            tmp=tmp->ptr;
        }
        cout<<tmp->value<<" ";
    }while(tmp->ptr != 0);
}

void search_element(node *&hptr){
    int num;
    hptr=hptr->ptr;
    while(hptr!=0){
        cout<<"enter num:";
        cin>>num;
        if(hptr->data==num){
            cout<<"sucess";
            return;
        }
     tmptr=hptr->ptr;
    }
    cout<<"search not sucessfull";
}
void delete_element(node *hptr)
{
    show_element(hptr);
    while(hptr!=nullptr){
        node *tptr=hptr;
        hptr=hptr->ptr;
        delete tptr;
    }
}

int main(){
    int ch,running=1;
    while(running){
    cout<<"\n1.insert_element\n2.show_element\n3.search\n4.delete\n5.exit";
    cout<<"\nenter any choice:";
    cin>>ch;
    switch(ch){
        case 1:
        insert_element(hptr);
        break;
        case 2:
        show_element(hptr);
        break;
        case 3:
        search_element(hptr);
        show_element(hptr);
        break;
        case 4:
        delete_element(hptr);
        cout<<"verified\n";
        show_element(hptr);
        break;
        case 5:
        running=0;
        break;
        default:
        cout<<"invalid choice";
    }}
}