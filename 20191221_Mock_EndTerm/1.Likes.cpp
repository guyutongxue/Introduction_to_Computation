#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int cnt=0,n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            int s=0;
            for(int j=1;j<=m;j++){
                int a;
                cin>>a;
                s+=a;
            }
            if(s>=(m+1)/2)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}