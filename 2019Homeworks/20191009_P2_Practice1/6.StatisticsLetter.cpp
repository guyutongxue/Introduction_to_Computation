#include<iostream>
#include<string>
using namespace std;
int main(){
    string pattern;
    getline(cin,pattern);
    int A=0,a=0,_=0;
    for(int i=0;i<pattern.length();i++){
        if(pattern[i]>='A'&&pattern[i]<='Z')A++;
        if(pattern[i]>='a'&&pattern[i]<='z')a++;
        if(pattern[i]>='0'&&pattern[i]<='9')_++;
    }
    cout<<A<<" "<<a<<" "<<_<<endl;
    return 0;
}