#include<iostream>
#include<string>
using namespace std;
int k,n;
string origin;
int main(){
    char comma;
    cin>>k>>comma>>n>>comma>>origin;
    string cur=origin;
    for(int j=1;j<=n;j++){
        int i=cur.length()-1;
        while(i+1&&(++cur[i]==k+'0')){
            cur[i]='0';
            i--;
        }
        if(i==-1)cur='1'+cur;
        cout<<cur<<(j%5&&j<n?',':'\n');
    }
    return 0;
}