#include<iostream>
using namespace std;
int q[10002],p[10002];
int n;
int m[102][102];
bool f[102][102];
void next(int& x,int& y,int& p){
    switch(p){
        case 1:
            if(f[x][y+1]){
                x++;
                p++;
            }
            else{
                y++;
            }
            break;
        case 2:{
            if(f[x+1][y]){
                y--;
                p++;
            }
            else{
                x++;
            }
            break;
        }
        case 3:{
            if(f[x][y-1]){
                x--;
                p++;
            }
            else{
                y--;
            }
            break;
        }
        case 4:{
            if(f[x-1][y]){
                y++;
                p=1;
            }
            else{
                x--;
            }
            break;
        }
    }
}
int main(){
    
    cin>>n;
    int n2=n*n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>m[i][j];
        }
    }
    for(int i=0;i<=n+1;i++){
        f[0][i]=true;
        f[i][0]=true;
        f[n+1][i]=true;
        f[i][n+1]=true;
    }
    /* 4
    3     1
       2
    */
    int x=1,y=1,pos=1;
    for(int i=1;i<=n*n;i++){
        p[i]=m[x][y];
        f[x][y]=true;
        next(x,y,pos);
    }
    cout<<p[1];
    for(int i=2;i<=n2;i++){
        if(i%2){
            cout<<" "<<p[i/2+1];
        }
        else{
            cout<<" "<<p[n2+1-i/2];
        }
    }
    
    return 0;
}