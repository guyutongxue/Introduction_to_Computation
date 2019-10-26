#include<iostream>
using namespace std;
int sum[100000];//sum of factor
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        sum[i]=1;
    }
    for(int i=2;2*i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            sum[j]+=i;
        }
    }
    for(int i=1;i<=n;i++){ 
        if (sum[i]>i&&sum[i]<=n&&sum[sum[i]]==i){
            cout<<i<<" "<<sum[i]<<endl;
        }
    }
    return 0;
}