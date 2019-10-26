#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int A[202];
int B[202];
int ptrA=0,ptrB=0;
bool isFound(int x){
    for(int i=1;i<=ptrA;i++){
        if(x==A[i])return true;
    }
    return false;
}
int main(){
    basic_string<char> str;
    getline(cin,str);
    int ele=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==','){
            A[++ptrA]=ele;
            ele=0;
        }
        else{
            ele=ele*10+(str[i]-'0');
        }
    }
    A[++ptrA]=ele;
    getline(cin,str);
    ele=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==','){
            if(isFound(ele))B[++ptrB]=ele;
            ele=0;
        }
        else{
            ele=ele*10+(str[i]-'0');
        }
    }
    if(isFound(ele))B[++ptrB]=ele;
    if(ptrB==0){
        cout<<"NULL"<<endl;
        return 0;
    }
    sort(B+1,B+ptrB+1);
    for(int i=1;i<=ptrB;i++){
        if(i>=2&&B[i]==B[i-1])continue;
        cout<<(i==1?"":",")<<B[i];
    }
    return 0;
}