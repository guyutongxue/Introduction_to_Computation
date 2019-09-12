#include<iostream>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int ab,bc,ca;
    ab=a+b;
    bc=b+c;
    ca=c+a;
    if(ab>c&&bc>a&&ca>b)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}