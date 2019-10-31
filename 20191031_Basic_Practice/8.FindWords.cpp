//Same as P2-5/5
#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;
map<string,int> m;
queue<string> q;
int main(){
    char ch;
    string str="";
    while(ch=cin.get(),ch!=EOF){
        if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z')||ch=='\''){
            str+=ch;
            continue;
        }
        if(str.empty())continue;
        map<string,int>::iterator it=m.begin();
        for(;it!=m.end();it++){
            if(it->first==str){
                it->second++;
                break;
            }
        }
        if(it==m.end()){
            q.push(str);
            m.insert(pair<string,int>(str,1));
        }
        str.clear();
    }
    while(!q.empty()){
        string s=q.front();
        q.pop();
        cout<<s<<" "<<m[s]<<endl;
    }
    return 0;
}