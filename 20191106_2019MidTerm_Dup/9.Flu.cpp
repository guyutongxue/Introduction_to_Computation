#include<iostream>
#include<vector>
using namespace std;
enum Status{
    Healthy,   //A healthy status, nothing happened.
    Ill,       //Has been inflected.
    Dangerous, //Will be ill next day.
    Covered    //Healthy and never will be inflected again.
};
vector<int> friends[100002];
Status st[100002];
int cnt=0;
int n;
int main(){
    int m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        st[i]=Healthy;
    }
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        friends[x].push_back(y);
        friends[y].push_back(x);
    }
    int root;
    cin>>root;
    st[root]=Ill;
    cnt++;
    int i;
    for(i=0;cnt;i++){
        for(int j=1;j<=n;j++){
            if(st[j]==Ill){
                for(vector<int>::iterator k=friends[j].begin();k!=friends[j].end();k++){
                    if(st[*k]==Healthy)st[*k]=Dangerous;
                }
            }
        }
        for(int j=1;j<=n;j++){
            switch(st[j]){
                case Healthy:
                case Covered: break;
                case Ill:{
                    st[j]=Covered;
                    cnt--;
                    break;
                }
                case Dangerous:{
                    st[j]=Ill;
                    cnt++;
                    break;
                }
            }
        }
        if(cnt==2000000000){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<i<<endl;
    return 0;
}