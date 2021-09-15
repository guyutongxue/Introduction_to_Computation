#include<iostream>
#include<string>
using namespace std;
string add(string a,string b){
    if(a.length()<b.length())swap(a,b);
    b=string(a.length()-b.length(),'0')+b;
    int jie=0;
    string res;
    for(int i=a.length()-1;i>=0;i--){
        int sum=a[i]-'0'+b[i]-'0'+jie;
        res=char(sum%10+'0')+res;
        jie=sum/10;
    }
    if(jie!=0)res=char(jie+'0')+res;
    return res;
}
int main(){
    string p;
    while(cin>>p){
        int len=p.length();
        string res=p;
        for(int i=1;i<=len;i++){
            res=add(res,p);
        }
        if(res.length()!=len){
            cout<<p<<" is not cyclic"<<endl;
            continue;
        }
        for(string::iterator i=res.begin();i!=res.end();i++){
            if(*i!='9'){
                cout<<p<<" is not cyclic"<<endl;
                goto EndOfWhile;
            }
        }
        cout<<p<<" is cyclic"<<endl;
        EndOfWhile:;
    }
    return 0;
}