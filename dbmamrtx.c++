#include <iostream>
#include <conio.h>
using namespace std;
int main(){
    int a[3][3]={{1,2,3},{3,4,5},{3,4,6}};
    int b[3][3]={{2,3,4},{3,6,5},{6,8,7}};
    int c[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    int i,j,k;
    cout<<"first matrix form:\n";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
           cout<<" "<<a[i][j];
        }
        cout<<"\n";
    }
    cout<<"second matrix form:\n";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){ 
           cout<<" "<<b[i][j];
        }
        cout<<"\n";
    }
    cout<<"multiplication of two matrix:\n";
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
              for(k=0;k<3;k++){
            c[i][j]=c[i][j]+a[i][k]*b[k][j];
        }
    }}
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
    cout<<" "<<c[i][j];
        }
        
        cout<<"\n";
        }
        cout<<"addition of two matrix:\n";
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                c[i][j]=a[i][j]+b[i][j];
            }
            }
        }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cout<<" "<<c[i][j];
            }
            cout<<"\n";
        }
        cout<<"subtract of two matrixes:\n";
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    c[i][j]=a[i][j]-b[i][j];
                }
            }
        }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cout<<" "<<c[i][j];
            }
            cout<<"\n";
        }
        cout<<"division of two matrixes:\n";
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                for(k=0;k<3;k++){
                    c[i][j]=a[i][j]/b[i][j];
                }
            }
        }
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                cout<<" "<<c[i][j];
            }
            cout<<"\n";
        }
    return 0;
}