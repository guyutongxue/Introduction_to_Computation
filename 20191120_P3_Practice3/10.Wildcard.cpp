//Same as P2-6/5
#include<iostream>
#include<string>
using namespace std;
bool isAbbr(string a,string b){
    if(a.length()==1){
        if(a=="*")return true;
        if(a=="?")return b.length()==1;
        return a==b;
    }
    bool res=true;
    for(int j=0,k=0;j<a.length();j++){
        if(a[j]==b[k]){if(k<b.length()){k++;continue;}else return false;}
        if(a[j]=='?'){if(k<b.length()){k++;continue;}else return false;}
        if(a[j]=='*'){
            if(k<b.length()){
                int r=false;
                for(int i=k;i<b.length();i++){
                    r=r||isAbbr(a.substr(j+1,a.length()-j-1),b.substr(i,b.length()-i));
                }
                res=res&&r;
            }
            break;
        }
        else return false;
    }
    return res;
}
int main(){
    string abbr,word;
    getline(cin,abbr);
    getline(cin,word);
    cout<<(isAbbr(abbr,word)?"":"not ")<<"matched"<<endl;
    return 0;
}