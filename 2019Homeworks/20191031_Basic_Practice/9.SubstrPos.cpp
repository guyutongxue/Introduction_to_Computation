#include<iostream>
#include<string>
using namespace std;
int findSub(string dest,string ptrn){
    for(int i=0;i<=dest.length()-ptrn.length();i++){
        if(dest.substr(i,ptrn.length())==ptrn)return i;
    }
    return -1;
}
int main(){
    string s,w;
    cin>>w>>s;
    cout<<findSub(s,w)<<endl;
    return 0;
}