#include<iostream>
#include<cstring>
using namespace std;
/**
 * '-': Empty
 * '#': Image-not-counted
 * 'A': Image-counted
*/
char a[202][202];
int n,m;
void search(int x,int y){
    a[x][y]='A';
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(!(i==x&&j==y)&&a[i][j]=='#'){
                search(i,j);
            }
        }
    }
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
    memset(a,'-',sizeof(a));
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]=='#'){
                cnt++;
                search(i,j);
                //debug();
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}