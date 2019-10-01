//4-9
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    double originalRate;
    int orAll,orAvail;
    cin>>orAll>>orAvail;
    originalRate=1.*orAvail/orAll;
    while(--n){
        int all,avail;
        cin>>all>>avail;
        double nowRate=1.*avail/all;
        if(nowRate-originalRate<-0.05)cout<<"worse"<<endl;
        else if(nowRate-originalRate>0.05)cout<<"better"<<endl;
        else cout<<"same"<<endl;
    }
    return 0;
}