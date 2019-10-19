#include<iostream>
using namespace std;
int n;
int m[15][15];
void next(int& x,int& y){
    if((x+y)%2==0){
        if(y==n)x++;
        else if(x==1)y++;
        else{
            x--;
            y++;
        }
    }
    else{
        if(x==n)y++;
        else if(y==1)x++;
        else{
            x++;
            y--;
        }
    }
}
int main(){
    cin>>n;
    int x=1,y=1;
    for(int i=1;i<=n*n;i++){
        m[x][y]=i;
        next(x,y);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<m[i][j]<<(j==n?"\n":" ");
        }
    }
    return 0;
}