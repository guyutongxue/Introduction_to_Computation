#define REUSE
#ifdef REUSE
//Same as P2-5/4
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    cin>>str;
    string rev=str;
    reverse(rev.begin(),rev.end());
    if(rev==str)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
#endif