#include<iostream>
#include<algorithm>
using namespace std;
int a[102];
int main(){
    while(true){
        int n;
        cin>>n;
        if(n==0)break;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        cout<<a[n/2+1]<<endl;
    }
    return 0;
}