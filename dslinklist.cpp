#include<iostream>
#include<conio.h>
using namespace std;
struct node{
    int item;
    node *ptr;
};
void traversenode *hptr{
    node *tptr=hptr;
    whiletptr!=0{
        cout<<tptr->item<<" ";
    }
}
void delete_elementnode *hptr{
    whilehptr!=0{
        node *tptr=hptr;
        hptr=hptr->ptr;
        delete tptr;
    }
}
void createnode *hptr{
    int item;
    node *nptr=new node;
    cout<<"enter item:";
    cin>>item;
    nptr->item=item;
    nptr->ptr=0;
    ifhptr==0{
        nptr=hptr;
    }
    else{
        node *tptr=hptr;
        whiletptr->ptr!=0
            tptr=tptr->ptr;
            tptr->ptr=nptr;
    }
}
    int main{
        node *hptr=0;
        char ch='y';
        whilech=='y' || ch=='y'{
            cout<<"do you want to insert new node:";
            cin>>ch;
            ifch=='y' || ch=='y'
            createhptr;
        }
        traversehptr;
        delete_elementhptr;
        return 0;
    }