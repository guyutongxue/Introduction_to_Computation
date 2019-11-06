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
int LCM(int a,int b){
    return a*b/GCD(a,b);
}
int main(){
    char comma;
    int a,b;
    cin>>a>>comma>>b;
    cout<<LCM(a,b)<<endl;
    return 0;
}