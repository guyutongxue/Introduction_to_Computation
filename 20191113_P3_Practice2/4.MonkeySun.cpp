#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 0: Available
 * 1: Wall or Searched
 * 2: Entrance
 * 3: Exit
*/
int a[52][52];
int n,m;
void debug(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    
}
bool search(int x,int y){
    if(a[x][y]==1)return false;
    if(a[x][y]==3)return true;
    a[x][y]=1;
    //debug();
    return search(x+1,y)||search(x,y+1)||search(x-1,y)||search(x,y-1);
}

int main(){
    cin>>n>>m;
    int sx,sy;
    for(int i=0;i<=max(n,m);i++){
        a[0][i]=a[i][0]=a[n+1][i]=a[i][m+1]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
            if(a[i][j]==2){
                sx=i;
                sy=j;
                a[i][j]=0;
            }
        }
    }
    cout<<(search(sx,sy)?"Yes":"No")<<endl;
    return 0;
}