#include<iostream>
using namespace std;
int main(){
    int s=0,n,i=2,q,j;
    cin>>n;
    for(;s+i<=n;)s+=i++;
    if(q=--i-n+s)for(j=2;j<=i;j++)cout<<j+(j>q)<<" \n"[j==i];
    else{
        for(int j=3;j<=i;j++)cout<<j<<" ";
        cout<<i+2<<'\n';
    }
}