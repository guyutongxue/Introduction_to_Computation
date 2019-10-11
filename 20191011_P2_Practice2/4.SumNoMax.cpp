//Same as P1-2/3
#include<iostream>
#include<algorithm>
using namespace std;
int a[102];
bool comp(int a,int b){return a>b;}
int main(){
    int n,s=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    sort(a+1,a+n+1,comp);
    int M=a[1],t=1;
    while(a[t]==M){
        t++;
    }
    t--;
    cout<<s-t*M<<endl;
    return 0;
}