#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        for(int l=min(a.length(),b.length());l>=0;l--){
            for(int i=0;i<=a.length()-l;i++){
                if(b.find(a.substr(i,l))!=string::npos){
                    cout<<l<<endl;
                    goto next;
                }
            }
        }
        next:;
    }
}