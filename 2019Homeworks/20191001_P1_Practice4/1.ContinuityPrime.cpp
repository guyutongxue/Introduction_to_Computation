#include<iostream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n<=1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}
int main(){
    int m,k;
    cin>>m>>k;
    for(int i=m;k;){
        m++;
        if(isPrime(m)){
            cout<<m<<(k==1?"":" ");
            k--;
        }
    }
    return 0;
}