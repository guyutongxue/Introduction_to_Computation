#include<iostream>
#define max(a,b) ((a>b)?a:b)
using namespace std;
int main(){
    int n,a[102][102]={},f[102][102]={};
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin>>a[i][j];
        }
    }
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            f[i][j]=a[i][j]+max(f[i+1][j],f[i+1][j+1]);
        }
    }
    cout<<f[1][1]<<endl;
    return 0;
}