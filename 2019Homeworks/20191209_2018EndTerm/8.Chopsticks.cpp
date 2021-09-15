#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[5002],f[5002][3002];
int main(){
    memset(f,0x7f,sizeof(f));
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        //cout<<a[i]<<" ";
        f[i][0]=0;
    }
    for(int i=n;i>=1;i--)
        for(int j=1;j<=k;j++)
            if(n-i+1>=3*j){
                f[i][j]=min(f[i+2][j-1]+(a[i+1]-a[i])*(a[i+1]-a[i]),f[i+1][j]);
                //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
            }
    cout<<f[1][k]<<endl;
}