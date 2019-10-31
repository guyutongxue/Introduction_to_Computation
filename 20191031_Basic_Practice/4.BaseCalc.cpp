//Same as P2-1/3
#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;
map<char,int> baseNum;
const string baseChar="0123456789abcdef";
void init(){
    for(int i=0;i<baseChar.length();i++){
        //baseNum.insert({baseChar[i],i}); //Not supported.
        baseNum.insert(pair<char,int>(baseChar[i],i));
    }
}
int convertToInt(int base,string n){
    int res=0;
    for(int i=0;i<n.length();i++){
        res=res*base+baseNum[n[i]];
    }
    return res;
}
string convertToBase(int base,int n){
    stack<char> charStack;
    do{
        charStack.push(baseChar[n%base]);
    }
    while(n/=base);
    string res="";
    while(!charStack.empty()){
        res+=charStack.top();
        charStack.pop();
    }
    return res;
}
int main(){
    init();
    int b1,b2,b3;
    string s1,s2;
    cin>>b1>>s1>>b2>>s2>>b3;
    cout<<convertToBase(b3,convertToInt(b1,s1)+convertToInt(b2,s2))<<endl;
    return 0;
}