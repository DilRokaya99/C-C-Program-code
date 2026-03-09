#include<iostream>
#include<conio.h>
#include<vector>
#include<algorithm>
using namespace std;

void initialize(vector<int> &arr,int &n);
void insert_element(vector<int> &arr,int &n);
void search(vector<int> &arr,int &n);
void delete_element(vector<int> &arr,int &n);
void display(vector<int> &arr,int &n);
void sort(vector<int> &arr,int &n);

int main (){
    int n,ch;
    int run=1;
    cout<<"enter elements:-";
    cin>>n;
    vector<int> arr(n);
    while(run){
        cout<<"\n\n";
        cout<<"\t\tchoose any options\n1.initialize\n2.insert\n3.search\n4.delete\n5.display\n6.exit\n7.sort\nchoice:-"; 
        cin>>ch;
        switch(ch){
            case 1:
            initialize(arr,n);
            break;

            case 2:
            insert_element(arr,n);
            cout<<"\nARRAY MODIFIED\n";
            display(arr,n);
            break;

            case 3:
            search(arr,n);
            break; 

            case 4:
            delete_element(arr,n);
            cout<<"\nARRAY MODIFIED\n";
            display(arr,n);
            break;

            case 5:
            display(arr,n);
            break;
           case 6:
            run=0;
            break;
            case 7:
            sort(arr,n);
            break;
            default:
            cout<<"\ninvalid choice";
        }
    }
    return 0;
}

void initialize(vector<int> &arr,int &n){
    cout<<"\nenter arr data:-\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

void insert_element(vector<int> &arr,int &n){
    int i,value;
    display(arr,n);
    in:
    cout<<"\nenter index :-";
    cin>>i;
    if(i<0 || i>n){
    cout<<"ERROR OUT OF RANGE";
        goto in;
    }
    cout<<"value=";
    cin>>value;
    arr.insert(arr.begin()+i,value);
    n=n+1;
}
void search(vector<int> &arr,int &n){
    int value;
    cout<<"enter number:";
    cin>>value;
    auto it=find(arr.begin(),arr.end(),value);
    if(it!=arr.end()){
        cout<<"\nelelment found at index "<<distance(arr.begin(),it);
    }
    else{
        cout<<"number not found";
    }
    getch;
}

void delete_element(vector<int> &arr,int &n){
    int i;
    display(arr,n);
    f:
    cout<<"\nenter index :-";
    cin>>i;
    if(i<0 || i>=n){
        cout<<"ERROR OUT OF RANGE";
        goto f;
    }
    arr.erase(arr.begin()+i);
    n=n-1;
}
void display(vector<int> &arr,int &n){
    cout<<"\nenter arr data:-\n";
    for(int i=0;i<n;i++){
    cout<<arr[i]<<"\t";
    }
    cout<<"\n";
    getch;
}
void sort(vector<int> &arr,int &n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                int tmp = arr[i];
                arr[i]=arr[j];
                arr[j]=tmp;
            }
        }
    }
}