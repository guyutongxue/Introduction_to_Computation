#include<iostream>
#include<string>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        char base=str[0];
        int cnt=0;
        for(int i=0;i<=str.length();i++){
            if(str[i]==base)cnt++;
            else{
                cout<<cnt<<base;
                base=str[i];
                cnt=1;
            }
        }
        cout<<endl;
    }
    return 0;
}