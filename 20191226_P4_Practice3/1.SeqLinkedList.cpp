#include<iostream>
#include<queue>
#include<sstream>
#include<string>
using namespace std;
int main(){
    priority_queue<int,vector<int>,greater<int> > q;
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string str;
        getline(cin,str);
        stringstream ss;
        ss<<str;
        int d;
        while(ss>>d)q.push(d);
        while(!q.empty()){
            cout<<q.top();
            q.pop();
            cout<<" \n"[q.empty()];
        }
    }
    return 0;
}