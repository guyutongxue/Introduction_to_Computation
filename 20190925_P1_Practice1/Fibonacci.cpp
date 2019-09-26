#include<iostream>
using namespace std;
int f[30]={0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368};
int main(){
    int n;
    cin>>n;
    while(n--){
        int t;
        cin>>t;
        cout<<f[t]<<endl;
    }
    return 0;
}