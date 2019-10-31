#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int findSub(string dest,string ptrn){
    for(int i=0;i<dest.length()-ptrn.length();i++){
        if(dest.substr(i,ptrn.length())==ptrn)return i+ptrn.length()-1;
    }
    return -1;
}
int main(){
    string S,S1,S2;
    getline(cin,S,',');
    getline(cin,S1,',');
    getline(cin,S2);
    int a=findSub(S,S1);
    reverse(S.begin(),S.end());
    reverse(S2.begin(),S2.end());
    int b=findSub(S,S2);
    if(a==-1||b==-1||a+b>S.length()-2)cout<<"-1"<<endl;
    else cout<<S.length()-2-(a+b)<<endl;
    return 0;
}