#include<iostream>
using namespace std;
void typesetting(string str){
    int i=80;
    if(str.length()<i){
        cout<<str<<endl;
        return;
    }
    while(str[i]!=' '){
        i--;
    }
    int t=i;
    do{
        i--;
    }
    while(str[i]==' ');
    cout<<str.substr(0,i+1)<<endl;
    do{
        t++;
    }
    while(t<str.length()&&str[t]==' ');
    typesetting(str.substr(t,str.length()-t));
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    string origin;
    getline(cin,origin);
    typesetting(origin);
    return 0;
}