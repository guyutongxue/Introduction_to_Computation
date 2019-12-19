#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[102][102];
int sum[102][102];
int n,m;
int main(){
    memset(sum,0,sizeof(sum));
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            sum[i][j]=a[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
        }
    }
    int res=0;
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            for(int i2=i+1;i2<=m;i2++){
                for(int j2=j+1;j2<=n;j2++){
                    if(sum[i2][j2]-sum[i][j2]-sum[i2][j]+sum[i][j]==0)res=max(res,(i2-i)*(j2-j));
                }
            }
        }
    }
    cout<<res<<endl;
    return 0;
}