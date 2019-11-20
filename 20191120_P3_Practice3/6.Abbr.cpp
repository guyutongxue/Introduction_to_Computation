//Same as P2-6/5
#include<iostream>
#include<string>
using namespace std;
bool isAbbr(string a,string b){
    if(a.length()==1){
        return b.find(a[0],0)!=string::npos;
    }
    bool res=false;
    for(int i=0;i<b.length();i++){
        if(a[0]==b[i]){
            res=res||isAbbr(a.substr(1,a.length()-1),b.substr(i+1,b.length()-i-1));
        }
    }
    return res;
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    while(n--){
        string abbr,word;
        getline(cin,abbr,':');
        getline(cin,word);
        cout<<(isAbbr(abbr,word)&&abbr.length()<word.length()?"YES":"NO")<<endl;
    }
    return 0;
}