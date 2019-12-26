#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;
string dic[110];
bool used[110];
int n,ans;
string astr;

void dfs(string substr,int templ,string tans){
    for(int i=0;i<n;i++){
        if(!used[i]){
            if(dic[i]==substr){
                if(ans>templ+substr.length()){
                     ans=templ+substr.length();
                     astr=tans+substr;
                }
                return;
            }
            else if(dic[i].length()>substr.length()&&dic[i].find(substr,0)==0){
                used[i]=true;
                string tstr=dic[i].substr(substr.length(),dic[i].length()-substr.length());
                dfs(tstr,templ+substr.length(),tans+substr);
                used[i]=false;
            }
            else if(dic[i].length()<substr.length()&&substr.find(dic[i],0)==0){
                used[i]=true;
                string tstr=substr.substr(dic[i].length(),substr.length()-dic[i].length());
                dfs(tstr,templ+dic[i].length(),tans+dic[i]);
                used[i]=false;
            }
        }
    }    
    return;
}
 
 
int main(){
    ans=1<<30;
    memset(used,0,sizeof(used));
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>dic[i];
    }
    sort(dic,dic+n);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(dic[i].find(dic[j],0)==0&&dic[i]!=dic[j]){
                used[i]=true;
                used[j]=true;
                const string tstr=dic[i].substr(dic[j].length(),dic[i].length()-dic[j].length());
                dfs(tstr,dic[j].length(),dic[j]);
                used[i]=false;
                used[j]=false;
            }
        }
    }
    cout<<astr;
    return 0;
}