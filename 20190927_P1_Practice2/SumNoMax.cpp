#include<iostream>
#include<algorithm>
using namespace std;
int a[102];
bool comp(int x,int y){
    return x>y;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,comp);
    int M=a[1],sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[1])continue;
        sum+=a[i];
    }
    cout<<sum<<endl;
    return 0;
}