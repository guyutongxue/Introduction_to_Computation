#include<iostream>
using namespace std;
int m1[101][101],m2[101][101];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>m1[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>m2[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<(m1[i][j]+m2[i][j])<<(j==n?"\n":" ");
        }
    }
}