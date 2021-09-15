#include<iostream>
#include<cstring>
using namespace std;
int n;
bool m[102][102];
bool mn[102][102];
bool f[102][102];
void spread(int i,int j){
    if(!f[i][j]&&!m[i][j]){
        mn[i][j]=true;
    }
}
void gen(int x,int y){
    if(m[x][y]){
        spread(x+1,y);
        spread(x-1,y);
        spread(x,y+1);
        spread(x,y-1);
    }
}
int main(){
    char str[102];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str;
        for(int j=1;j<=n;j++){
            if(str[j-1]=='#')f[i][j]=true;
            else f[i][j]=false;
            if(str[j-1]=='.')m[i][j]=false;
            if(str[j-1]=='@')m[i][j]=true;
        }
    }
    for(int i=0;i<=n+1;i++){
        f[0][i]=true;
        f[i][0]=true;
        f[n+1][i]=true;
        f[i][n+1]=true;
    }
    int d;
    cin>>d;
    while(--d){
        memcpy(mn,m,sizeof(m));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                gen(i,j);
            }
        }
        memcpy(m,mn,sizeof(mn));
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(mn[i][j])cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}