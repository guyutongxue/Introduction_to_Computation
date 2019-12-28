#include<iostream>
#include<cstring>
using namespace std;
int a[110][110],map[110][110],ans;
int m,n;
int kk[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int dp(int x,int y){
    int max=0;
    if(x<0||x>=n||y<0||y>=m)
    return 0;
    if(map[y][x]!=-1){
        if(ans<map[y][x])
            ans=map[y][x];
        return map[y][x];
    }
   
    for(int i=0;i<4;i++){
        if(a[y][x]<a[y+kk[i][1]][x+kk[i][0]]){
           int k=dp(x+kk[i][0],y+kk[i][1]);
           if(max<k)
           max=k;
        }
    }
    map[y][x]=max+1;
    if(ans<map[y][x])
        ans=map[y][x];
    return map[y][x];
}
int main(){
    cin>>m>>n;
    memset(map,0,sizeof(map));
    ans=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            map[i][j]=-1;
        }
    }
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(map[i][j]==-1)
    dp(j,i);
    cout<<ans<<endl;
    return 0;
}