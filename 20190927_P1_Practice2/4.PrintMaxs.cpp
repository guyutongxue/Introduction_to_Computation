#include<iostream>
#include<algorithm>
using namespace std;
int a[1002];
bool comp(int x,int y){
    return x>y;
}
int main(){
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,comp);
    cin>>m;
    for(int i=1;i<=m;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}