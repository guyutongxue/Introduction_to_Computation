#include<iostream>
using namespace std;
int count(int x,int d){
    int res=0;
    do{
        if(x%10==d)res++;
    }
    while(x/=10);
    return res;
}
int main(){
    int n,d,res=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        res+=count(i,d);
    }
    cout<<res<<endl;
    return 0;
}