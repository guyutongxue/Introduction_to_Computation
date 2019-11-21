#include<iostream>
#include<sstream>
#include<stack>
#include<algorithm>
using namespace std;
stringstream ss;
inline int getPrior(char x){
    if(x=='*'||x=='/')return 2;
    else return 1;
}
inline int calc(char p,int x,int y){
    switch(p){
        case '+':return x+y;
        case '-':return x-y;
        case '*':return x*y;
        case '/':return x/y;
    }
}
int parse(){
    string c;
    stack<int> b;
    stack<char> s;
    while(ss>>c){
        if(c=="(")break;
        else if(c==")")b.push(parse());
        else if(c=="+"||c=="-"||c=="*"||c=="/"){
            while(!s.empty()&&getPrior(c[0])<getPrior(s.top())){
                int a1=b.top();b.pop();
                int a2=b.top();b.pop();
                b.push(calc(s.top(),a1,a2));
                s.pop();
            }
            s.push(c[0]);
        }
        else b.push(atoi(c.c_str()));
    }
    while(!s.empty()){
        int a1=b.top();b.pop();
        int a2=b.top();b.pop();
        b.push(calc(s.top(),a1,a2));
        s.pop();
    }
    return b.top();
}
void getInverseStream(string a){
    if(a[0]=='-'||a[0]=='+'){//Prefix -/+ at the beginning
            a='0'+a;
    }
    for(int i=1;i<a.length();i++){
        if(a[i-1]<'0'||a[i-1]>'9'||a[i]<'0'||a[i]>'9'){//if not adjacent digits
            if((a[i-1]=='(')&&(a[i]=='-'||a[i]=='+')){//prefix -/+ before '('
                a.insert(i,1,'0');
                a.insert(i,1,' ');
                i+=2;
            }
            a.insert(i,1,' ');//add space between symbols & digits
            i++;
        }
    }
    //cout<<a<<endl;
    ss<<a;
    string temp;
    stack<string> st;//use a stack to inverse this space=splitted array
    while(ss>>temp)
        st.push(temp);
    ss.clear();
    a.clear();
    while(!st.empty()){
        a+=st.top();
        a+=" ";
        st.pop();
    }
    //cout<<a<<endl;
    ss<<a;
}
int main(){
    string a;
    while(getline(cin,a)){
        getInverseStream(a);
        cout<<parse()<<endl;
        ss.clear();
    }
    return 0;
}