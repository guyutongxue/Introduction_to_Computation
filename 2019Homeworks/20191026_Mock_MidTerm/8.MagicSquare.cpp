#include<iostream>
using namespace std;
int m[23][23];
bool f[23][23];
int n;
void next(int& x,int& y){
    if(x==1){
        if(y==n){
            x++;
            return;
        }
        y++;
        x=n;
        return;
    }
    if(y==n){
        y=1;
        x--;
        return;
    }
    if(f[x-1][y+1]){
        x++;
        return;
    }
    
    y++;
    x--;
}
int main(){
    cin>>n;
    for(int i=0;i<=n+1;i++){
        f[0][i]=true;
        f[i][0]=true;
        f[n+1][i]=true;
        f[i][n+1]=true;
    }
    int x=1,y=n/2+1;
    for(int i=1;i<=n*n;i++){
        m[x][y]=i;
        f[x][y]=true;
        next(x,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<m[i][j]<<(j==n?"\n":" ");
        }
    }
    return 0;
}