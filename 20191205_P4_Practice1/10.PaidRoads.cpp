#include<iostream>
#include<cstring>
using namespace std;
int n,m;
int visit[11];
int mmin=1<<30;
struct Road{
	int u,v;
	int c;
	int p,r;
};
Road a[12];
void search(int s,int current){
	if(s==n&&current<mmin){
		mmin=current;
		return;
	}
	for(int i=1;i<=m;i++){
		if(s==a[i].u&&visit[a[i].v]<=3){
			int v=a[i].v;
			if(visit[a[i].c]){
                visit[v]++;
				search(v,current+a[i].p);
            }
			else{
                visit[v]++;
                search(v,current+a[i].r);
            }
			visit[v]--;
		}
	}
	return;
}
 
int main(){
	cin>>n>>m;
    memset(visit,0,sizeof(visit));
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].c>>a[i].p>>a[i].r;
    }
    visit[1]=1;
    search(1,0);
    if(mmin==1<<30){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<mmin<<endl;
    }
	return 0;
}