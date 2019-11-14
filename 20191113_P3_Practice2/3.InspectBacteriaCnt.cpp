#include<iostream>
#include<cstring>
using namespace std;
/**
 * 0: Empty
 * 1: Bacteria-not-counted
 * 2: Bacteria-counted
*/
int a[102][102];
int n,m;
void search(int x,int y){
    a[x][y]=2;
    if(a[x+1][y]==1)search(x+1,y);
    if(a[x][y+1]==1)search(x,y+1);
    if(a[x-1][y]==1)search(x-1,y);
    if(a[x][y-1]==1)search(x,y-1);
}
void debug(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
int main(){
    memset(a,0,sizeof(a));
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==1){
                cnt++;
                search(i,j);
                //debug();
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}