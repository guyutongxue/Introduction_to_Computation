#include<iostream>
#include<algorithm>
using namespace std;
/**
 * 0: Available
 * 1: Wall or Searched
 * 2: Entrance
 * 3: Exit
*/
char a[52][52];
int n,m,cnt;
void debug(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    
}
void search(int x,int y){
    if(a[x][y]=='#')return;
    cnt++;
    a[x][y]='#';
    //debug();
    search(x+1,y);
    search(x,y+1);
    search(x-1,y);
    search(x,y-1);
}

int main(){
    while(cin>>m>>n){
        if(n==0&&m==0)break;
        cnt=0;
        int sx,sy;
        for(int i=0;i<=max(n,m);i++){
            a[0][i]=a[i][0]=a[n+1][i]=a[i][m+1]='#';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='@'){
                    sx=i;
                    sy=j;
                    a[i][j]='.';
                }
            }
        }
        search(sx,sy);
        cout<<cnt<<endl;
    }
    return 0;
}