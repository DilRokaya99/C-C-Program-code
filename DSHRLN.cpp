#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
bool isprime(int n)
{
    if(n<2)
    {
    return false;
    }
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;

}


void disp(const std::vector<int>&v)
{
    for(int n:v)
    {
    std::cout<<n<<" ";
    std::cout<<std::endl;
    std::vector<int>primenum;
    }

    for(int n:v)
    {
        if(isprime(n))
        {
            std::cout<<n<<" is prime"<<std::endl;
        }
        else{
            std::cout<<n<<" is not prime"<<std::endl;
        }
    }
    return ;

}

void insert_beg(std::vector<int>&a,int n)
{
    
    a.insert(a.begin(),n);
    std::cout<<"Updated array:";
    disp(a);  
    
    
}


void insert_loc(std::vector<int>&a,int n,int l)
{
    if(l>=0&&l<=a.size())
    {
        a.insert(a.begin()+l,n);
        std::cout<<"Updated array:";
        disp(a);
    }
    else
    {
        std::cout<<"Invalid position"<<std::endl;
    }
}

void insert_end(std::vector<int>&a,int n)
{
    a.push_back(n);
    std::cout<<"Updated array:";
    disp(a);
}

void del_beg(std::vector<int>&a)
{
    a.erase(a.begin());
    std::cout<<"Updated array:";
    disp(a);
}

void del_pos(std::vector<int>&a,int l)
{
    if(l>=0&&l<a.size())
    {
        a.erase(a.begin()+l);
        std::cout<<"Updated array:";
        disp(a);
    }
    else
    {
        std::cout<<"Invalid location"<<std::endl;
    }
}

void del_end(std::vector<int>&a)
{
    a.pop_back();
    std::cout<<"Updated array:";
    disp(a);
}

void del_element(std::vector<int>&a,int n)
{
    a.erase(std::remove(a.begin(),a.end(),n),a.end());
    std::cout<<"Updated array:";
    disp(a);
}

int search(const std::vector<int>&a,int n)
{
    auto it=std::find(a.begin(),a.end(),n);
    if(it!=a.end())
    {
        return std::distance(a.begin(),it);
    }
    else
    {
        return -1;
    }    
}

int main()
{
    std::vector<int>a;
    int n,l;
    std::cout<<"Enter the number of elements of array:";
    std::cin>>n;
    std::cout<<"Enter the elements of array:";
    for(int i=0;i<n;i++)
    {
        std::cin>>l;
        a.push_back(l);
    }
    std::cout<<"Array elements:";
    disp(a);
    int choice;
    char ch;
    do
    {
        std::cout<<"\n::::Menu::::\n";
        std::cout<<"\nPress 1 for insert an element at beginning";
        std::cout<<"\nPress 2 for insert an element at given location";
        std::cout<<"\nPress 3 for insert an element at end";
        std::cout<<"\nPress 4 for delete an element at beginning";
        std::cout<<"\nPress 5 for delete an element at a given position";
        std::cout<<"\nPress 6 for delete an element at end";
        std::cout<<"\nPress 7 for delete an element by entering an element";
        std::cout<<"\nPress 8 for the searching of an element";
        std::cout<<"\nPress 9 for the display of vector";
        std::cout<<"\nPress 10 for exit";
        std::cout<<"\nEnter your choice:";
        std::cin>>choice;
        switch(choice)
        {
            do{
            case 1:std::cout<<"Enter the element to insert:";
            std::cin>>n;
            insert_beg(a,n);
            std::cout<<"do you need to run this func once more time ?(Y/N):";
            std::cin>>ch;
            }while(ch=='y' || ch=='Y');
            break;
            
            case 2:
            do{
                std::cout<<"Enter the element to insert:";
            std::cin>>n;
            std::cout<<"Enter the location:";
            std::cin>>l;
            insert_loc(a,n,l);
             char ch;
std::cout<<"do you need to run this func once more time ?(Y/N):";
std::cin>>ch;
}while(ch=='y'||ch=='Y');
    
    
            break;
    

            case 3:
            do{
                std::cout<<"Enter the element to insert";
            std::cin>>n;
            insert_end(a,n);
            std::cout<<"do you need to run this func once more time ?(Y/N):";
            std::cin>>ch;
            }while(ch=='y'||ch=='Y');

    
            break;


            case 4:
            do{del_beg(a);
            std::cout<<"do you need to run this func once more time ?(Y/N):";
            std::cin>>ch;
            }while(ch=='y'||ch=='Y');
    
            break;
            

            case 5:
            do{std::cout<<"Enter the location to delete an element:";
            std::cin>>l;
            del_pos(a,l);
            std::cout<<"do you need to run this func once more time ?(Y/N):";
            std::cin>>ch;
            }while(ch=='y'||ch=='Y');
    
            break;

            case 6:
            do{
            del_end(a);
            std::cout<<"do you need to run this func once more time ?(Y/N):";
            std::cin>>ch;
}while(ch=='y'||ch=='Y');
            
            break;

            case 7:
            do{std::cout<<"Enter the element to delete:";
            std::cin>>n;
            del_element(a,n);
std::cout<<"do you need to run this func once more time ?(Y/N):";
std::cin>>ch;
}while(ch=='y'||ch=='Y');
            break;

            case 8:do{
                std::cout<<"Enter the element to find:";
            std::cin>>n;
            l=search(a,n);
            if(l!=-1)
            {
                std::cout<<"Element "<<n<<" found at location "<<l;
                std::cout<<"\n";
            }
            else
            {
                std::cout<<"Element not found in the array";
            }
std::cout<<"do you need to run this func once more time ?(Y/N):";
std::cin>>ch;
}while(ch=='y'||ch=='Y');
            break;

            case 9:std::cout<<"Elements of array:";
            disp(a);
            break;

            case 10:std::cout<<"Exiting.....\n";
            break;
        }
    }
    while(choice!=10);
    return 0;
}