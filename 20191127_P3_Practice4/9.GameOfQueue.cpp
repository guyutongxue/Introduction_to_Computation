// Same as P3-2/5
#include<iostream>
#include<string>
#include<stack>
using namespace std;
char a,b;
stack<int> s;
inline void GetWhichChar(string x){
    a=x[0];
    for(int i=1;i<x.length();i++){
        if(x[i]!=a){
            b=x[i];
            return;
        }
    }
}
int main(){
    string q;
    cin>>q;
    GetWhichChar(q);
    for(int i=0;i<q.length();i++){
        if(q[i]==a)s.push(i);
        else{
            cout<<s.top()<<" "<<i<<endl;
            s.pop();
        }
    }
    return 0;
}