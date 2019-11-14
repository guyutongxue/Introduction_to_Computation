#include<iostream>
using namespace std;
int main(){
    int t,n,s[18];
    cin>>t>>n;
    int m=0,r[70000];//Possible result
    for(int i=2;i<=n;i++){
        cin>>s[i];
        for(int j=1;j<=m;j++){
            r[j+m]=r[j]*s[i];
        }
        m*=2;
        r[++m]=s[i];
    }
    for(int i=1;i<=m;i++){
        if(r[i]==t){
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
    return 0;
}