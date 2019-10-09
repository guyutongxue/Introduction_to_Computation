#include<iostream>
#include<stack>
using namespace std;
stack<bool> a;
stack<bool> b;
stack<bool> s;//sum
bool c=false;//step-in
bool pop_s(stack<bool>& sb){
    if(sb.empty())return false;
    bool res=sb.top();
    sb.pop();
    return res;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        c=false;
        string x,y;
        cin>>x>>y;
        for(int i=0;i<x.length();i++){
            a.push(x[i]-'0');
        }
        for(int i=0;i<y.length();i++){
            b.push(y[i]-'0');
        }
        while(!(a.empty()&&b.empty())){
            bool pa=pop_s(a);
            bool pb=pop_s(b);
            // Full-adder in logic circuit.
            bool ps=(pa^pb^c);
            c=(pa&&pb)||(pb&&c)||(c&&pa);
            s.push(ps);
        }
        if(c)cout<<'1';//Last step-in.
        while(!s.empty()){
            bool ps=s.top();
            cout<<(ps?'1':'0');
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}