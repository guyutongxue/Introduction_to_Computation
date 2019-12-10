//Similar with 2017EndTerm/8
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int mpp[410][410],p[410],liu[410][410],path[410];
int n,f,d,sum;
void init(){
    int x,y,m;
    memset(mpp,0,sizeof(mpp));
    memset(liu,0,sizeof(liu));
    for(int i=1;i<=n;i++){
        cin>>x;
        y=1;
        for(int j=1;j<=x;j++){
            cin>>m;
            mpp[m+200][i]=1;
            mpp[0][m+200]=1;
        }
        mpp[i][i+100]=1;
        for(int j=1;j<=y;j++){
            m=i;
            mpp[i+100][m+300]=1;
            mpp[m+300][401]=1;
        }
    }
}
void inten(){
    queue<int>q;
    while(true){
        memset(path,-1,sizeof(-1));
        memset(p,0,sizeof(p));
        p[0]=1<<30;
        q.push(0);
        while(!q.empty()){
            int ans=q.front();
            q.pop();
            for(int i=0; i<=401; i++){
                if(!p[i]&&liu[ans][i]<mpp[ans][i]){
                    p[i]=min(p[ans],mpp[ans][i]-liu[ans][i]);
                    path[i]=ans;
                    q.push(i);
                }
            }
        }
        if(!p[401])
            break;
        sum+=p[401];
        int tem=401;
        while(path[tem]!=-1){
            int v=path[tem];
            liu[v][tem]+=p[401];
            liu[tem][v]-=p[401];
            tem=v;
        }
    }
}
int main(){
    cin>>n>>f;
    d=n;
    sum=0;
    init();
    inten();
    cout<<sum<<endl;
}