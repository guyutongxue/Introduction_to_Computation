#include<iostream>
using namespace std;
int a[12];
int b[12];
int ptra=1,ptrb=1;
int main(){
    for(int i=1;i<=10;i++){
        cin>>a[i];
    }
    for(int i=1;i<=10;i++){
        cin>>b[i];
    }
    for(int i=1;i<=20;i++){
        if(ptra>10)cout<<b[ptrb++];
        else if(ptrb>10) cout<<a[ptra++];
        else if(a[ptra]<b[ptrb])cout<<a[ptra++];
        else cout<<b[ptrb++];
        cout<<(i==20?"":" ");
    }
    return 0;
}