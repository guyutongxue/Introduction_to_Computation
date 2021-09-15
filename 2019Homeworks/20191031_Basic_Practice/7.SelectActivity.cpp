#include<iostream>
#include<algorithm>
using namespace std;
struct Activity{
    int start;
    int end;
    bool operator<(Activity b)const{return end<b.end;}
};
int n;
Activity q[1000002];
int calc(int startpos,int start){
    int m=0;
    for(int i=startpos;i<n;i++){
        if(q[i].start>=start){
            m=max(m,1+calc(i+1,q[i].end));
        }
    }
    return m;
}
/**
 * 注解：
 * 这道题使用贪心算法，我算法很差，并不能很好地掌握。
 * 这里的贪心策略是，活动越早结束的越优先。
 * 关于贪心策略的最优性证明暂且不能理解。
*/
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>q[i].start>>q[i].end;
    }
    sort(q+1,q+n+1);
    int ans=0;
    for(int i=1,l=-1e9;i<=n;i++)
		if(q[i].start>=l){
			ans++;
            l=q[i].end;
        }
    cout<<ans<<endl;
    return 0;
}