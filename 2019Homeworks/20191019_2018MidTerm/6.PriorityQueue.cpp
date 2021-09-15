/**
 * I FAILED TO AVOID USING STL.
 * SO IF ANYBODY WHO WANT TO PASS THIS PROBLEM,
 * TRY OTHER METHOD.
*/

#include<iostream>
#include<queue>
#include<algorithm>
#include<string>
using namespace std;
priority_queue<int,vector<int>,greater<int> >q;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    cin>>m;
    for(int i=1;i<=m;i++){
        string cmd;
        cin>>cmd;
        if(cmd=="ADD"){
            int x;
            cin>>x;
            q.push(x);
        }
        if(cmd=="EXTRACT-MIN"){
            if(q.empty())cout<<"NULL"<<endl;
            else{
                cout<<q.top()<<endl;
                q.pop();
            }
        }
    }
    return 0;

}