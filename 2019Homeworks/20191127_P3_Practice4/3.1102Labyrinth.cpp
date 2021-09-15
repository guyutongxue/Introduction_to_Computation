#include<iostream>
#include<algorithm>
using namespace std;
/**
 * '.': Available
 * '#': Wall or Searched
 * 'E': Exit
*/
char a[102][102];
int n;
void debug(){
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            cout<<a[i][j];
        }
        cout<<endl;
    }
    
}
bool search(int x,int y){
    if(a[x][y]=='#')return false;
    if(a[x][y]=='E')return true;
    a[x][y]='#';
    //debug();
    return search(x+1,y)||search(x,y+1)||search(x-1,y)||search(x,y-1);
}

int main(){
    int w;
    cin>>w;
    while(w--){
        cin>>n;
        int sx,sy;
        for(int i=0;i<=n+1;i++){
            a[0][i]=a[i][0]=a[n+1][i]=a[i][n+1]='#';
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        cin>>sx>>sy;
        sx++;sy++;
        int ex,ey;
        cin>>ex>>ey;
        if(a[sx][sy]=='#'||a[ex+1][ey+1]=='#')cout<<"NO"<<endl;
        else{
            a[ex+1][ey+1]='E';
            cout<<(search(sx,sy)?"YES":"NO")<<endl;
        }
    }
    return 0;
}