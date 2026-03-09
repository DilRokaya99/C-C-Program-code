#include<iostream>
#include<conio.h>
using namespace std;
int linsearch(int a[],int n,int x){ 
int i;
for(i=0;i<n;i++){
    int it++;
    if(a[i]==x){
        return i;
    }
}return -1;
}
int main(){
    int a[]={2,4,3,5,6,8,7};
    int x=7;int it=0;
   int index=linsearch(a,x,it);
    if(index!=-1){
        cout<<"elepment"<<index;
    }
    else{
        cout<<"not found";
    }
    cout<<it;
    return 0;
}