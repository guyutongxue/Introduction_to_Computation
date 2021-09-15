#include<iostream>
using namespace std;
int main(){
    int n,k,a[1002];
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<i;j++){
            if(a[i]+a[j]==k){
                cout<<"yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"no"<<endl;
    return 0;
}