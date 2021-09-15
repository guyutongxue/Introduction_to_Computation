#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    double c=0;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        c+=0.1*(ceil(1.*t/70));
    }
    cout<<c<<endl;
    return 0;
}