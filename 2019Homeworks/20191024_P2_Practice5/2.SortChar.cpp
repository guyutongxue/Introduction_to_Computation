//14-2
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool comp(char a,char b){
    return a>b;
}
int main(){
    string str;
    getline(cin,str);
    int length=str.length();
    string l=str.substr(0,length/2);
    sort(l.begin(),l.end(),comp);
    if(length&1){
        cout<<str.substr(length/2+1,length/2)<<str[length/2]<<l<<endl;
    }
    else{
        cout<<str.substr(length/2,length/2)<<l<<endl;
    }
    return 0;
}