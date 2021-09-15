#include<iostream>
#include<algorithm>
using namespace std;
int sum[100002];
int main(){
    int n,k;
    cin>>n>>k;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        sum[i]=sum[i-1]+x;
    }
    int mmin=1<<30;
    for(int i=1;i<=k;i++){
        mmin=min(mmin,sum[i+n-k]-sum[i]);
    }
    cout<<sum[n]-mmin<<endl;
    return 0;
}