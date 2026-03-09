#include<iostream>
#include<conio.h>
#include<vector>

void initialize(std::vector<int> &a);
void display(std::vector<int> &a);
void insert_element(std::vector<int> &a);
void delete_element(std::vector<int> &a);
void search(std::vector<int> &a);

int main(){
    int n,c;
    bool running=1;
    std::cout<<"number of members:-";
    std::cin>>n;
    std::vector<int> a(n);
    while(running){
        std::cout<<"\n\n\n";
        std::cout<<"\t\tchoose one of the following options\n1.initialize\n2.insert\n3.delete\n4.display\n5.search\n6.exit\nchoice:-"; 
        std::cin>>c;
        switch(c){
            case 1:
            initialize(a);
            break;

            case 2:
            insert_element(a);
            std::cout<<"\nARRAY MODIFIED\n";
            display(a);
            break;

            case 3:
            delete_element(a);
            std::cout<<"\nARRAY MODIFIED\n";
            display(a);
            break;

            case 4:
            display(a);
            break;

            case 5:
            search(a);
            break;

            case 6:
            running=0;
            break;
        }
    }
    return 0;
}

void initialize(std::vector<int> &a){
    std::cout<<"\nenter array data:-\n";
    for(int i=0;i<a.size();i++){
        std::cin>>a[i];
    }
}

void display(std::vector<int> &a){
    std::cout<<"\narray data:-\n";
    for(int i=0;i<a.size();i++){
    std::cout<<a[i]<<" ";
    }
    std::cout<<"\n";
    getch;
}

void insert_element(std::vector<int> &a){
    int i,v;
    display(a);
    input:
    std::cout<<"\nenter index :-";
    std::cin>>i;
    if(i<0 || i>a.size()){
        std::cout<<"ERROR OUT OF RANGE";
        goto input;
    }
    std::cout<<"value=";
    std::cin>>v;
    a.insert(a.begin()+i,v);
}

void delete_element(std::vector<int> &a){
    int i;
    display(a);
    input:
    std::cout<<"\nenter index :-";
    std::cin>>i;
    if(i<0 || i>=a.size()){
        std::cout<<"ERROR OUT OF RANGE";
        goto input;
    }
    a.erase(a.begin()+i);
}

void search(std::vector<int> &a){
    int v,count=0;
    std::cout<<"value=";
    std::cin>>v;
    for(int i=0;i<a.size();i++){
        if(a[i]==v){
            count += 1;
        }
    }
    if(count>0){
        std::cout<<"\nvalue "<<v<<" found "<<count<<" times in the array\n";
    }
    else{
        std::cout<<"\nvalue "<<v<<" not found in array\n";
    }
    getch();
}