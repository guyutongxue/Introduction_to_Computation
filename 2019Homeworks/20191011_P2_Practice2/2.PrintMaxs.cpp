//Same problem as 1-2/4
#include<iostream>
#include<algorithm>
using namespace std;
int a[1002];
bool comp(int a,int b){return a>b;}
int main(){
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>k;
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=k;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}