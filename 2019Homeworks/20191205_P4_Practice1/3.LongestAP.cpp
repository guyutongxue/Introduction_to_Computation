#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct AP{
    AP(int x1,int x2,int x3){
        a1=x1;
        d=x2;
        n=x3;
    }
    int a1;
    int d;
    int n;
    bool operator>(AP b)const{
        if(n!=b.n)return n>b.n;
        if(d!=b.d)return d>b.d;
        return a1>b.a1;
    }
};
int n;
int a[5002];
int dp[5002][5002];
int main(){
    ios::sync_with_stdio(false);
    //freopen("Untitled-1.txt","r",stdin);
    AP mx(0,0,0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            dp[i][j]=2;
        }
    }
    for(int j=n-1;j>=2;j--){
        int i=j-1;
        int k=j+1;
        while(i>=1&&k<=n){
            int lp=a[j]-a[i];
            int rp=a[k]-a[j];
            if(lp<rp)i--;
            else if(lp>rp)k++;
            else{
                dp[i][j]=dp[j][k]+1;
                //if(n==500&&a[i]==242&&a[j]==454)cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
                if(dp[i][j]>=3){
                    AP cur(a[i],a[j]-a[i],dp[i][j]);
                    if(cur>mx)mx=cur;
                }
                i--;
                //k++;
            }
        }
    }
    if(mx.n==0){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<mx.n;i++){
        cout<<mx.a1+i*mx.d;
        if(i!=mx.n-1)cout<<',';
    }
    return 0;
}