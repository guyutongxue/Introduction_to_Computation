#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct SubStr{
    string sub;
    int num;
    SubStr(string x){
        sub=x;
        num=1;
    }
    bool operator<(SubStr b)const{
        return num>b.num;
    }
};
vector<SubStr> v;
int main(){
    int n;
    string str;
    cin>>n>>str;
    for(int i=0;i<str.length();i++){
        string sub=str.substr(i,n);
        for(vector<SubStr>::iterator i=v.begin();i!=v.end();i++){
            if(i->sub==sub){
                i->num++;
                goto EndOfOuterFor;
            }
        }
        v.push_back(SubStr(sub));
        EndOfOuterFor:;
    }
    stable_sort(v.begin(),v.end());
    if(v.front().num==1){
        cout<<"NO"<<endl;
        return 0;
    }
    int maxnum=v.front().num;
    cout<<maxnum<<endl;
    cout<<v.front().sub<<endl;
    for(int i=1;v[i].num==maxnum;i++){
        cout<<v[i].sub<<endl;
    }
    return 0;
}