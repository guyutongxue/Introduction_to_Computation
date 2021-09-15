#include<iostream>
using namespace std;
int R,C;
int m[102][102];
int main(){
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>m[i][j];
        }
    }

    for(int k=2;k<=C+R;k++){
        for(int i=1;i<=R;i++){
            for(int j=1;j<=C;j++){
                if(i+j==k)cout<<m[i][j]<<endl;
            }
        }
    }
    return 0;
}