#include<iostream>
#include<conio.h>
using namespace std;
int main(){
    int mid,n,beg=0,end=6,a[5]={1,2,4,3,6};
    cout<<"enter any vlaue:";
    cin>>n;
    while(beg<=end){
        mid=beg+end/2;
        if(a[mid]==n){
            cout<<"found";
            break;
        }
        if(a[mid]<n){
            beg=mid+1;
        }
        if(a[mid]>n){
            end=mid-1;
        }
    }
    getch();
}