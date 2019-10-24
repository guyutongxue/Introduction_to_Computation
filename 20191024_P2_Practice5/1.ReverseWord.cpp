#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
stack<string> st;
int main(){
    string str;
    while(cin>>str){
        st.push(str);
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
        if(!st.empty())cout<<" ";
    }
    return 0;
}