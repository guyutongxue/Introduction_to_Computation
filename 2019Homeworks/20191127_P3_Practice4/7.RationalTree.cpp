#include<iostream>
using namespace std;
int GCD(int a,int b){
    if(a<b)swap(a,b);
    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        a/=GCD(a,b);
        b/=GCD(a,b);
        int d=0,res=0;
        while(a!=1||b!=1){
            if(a>b){
                a-=b;res+=(1<<d);
            }
            else b-=a;
            d++;
        }
        cout<<(1<<d)+res<<endl;
    }
    return 0;
}