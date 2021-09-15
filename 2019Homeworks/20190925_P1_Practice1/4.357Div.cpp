//4-4
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n%105==0)cout<<"3 5 7"<<endl;
    else if(n%35==0)cout<<"5 7"<<endl;
    else if(n%21==0)cout<<"3 7"<<endl;
    else if(n%15==0)cout<<"3 5"<<endl;
    else if(n%7==0)cout<<"7"<<endl;
    else if(n%5==0)cout<<"5"<<endl;
    else if(n%3==0)cout<<"3"<<endl;
    else cout<<"n"<<endl;
    return 0;
}