//FAIL TO PASS BUT REASON NOT FOUND YET
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
int t[10000010];
inline int transfer(char x){
    if(x<='9')return x-'0';
    if(x<='C')return 2;
    if(x<='F')return 3;
    if(x<='I')return 4;
    if(x<='L')return 5;
    if(x<='O')return 6;
    if(x<='S')return 7;
    if(x<='V')return 8;
    if(x<='Y')return 9;
    else return 0;
}
int main(){
    //ios::sync_with_stdio(false);
    memset(t,0,sizeof(t));
    int n;
    cin>>n;
    cin.ignore();
    for(int i=1;i<=n;i++){
        int num=0;
        for(int j=1;j<=7;){
            char c=cin.get();
            if(c=='\n'||c=='-')continue;
            (num*=10)+=transfer(c); //就是这一行tm死活过不去
            j++;
        }
        t[num]++;
    }
    bool isEmpty=true;
    for(int i=0;i<=9999999;i++){
        if(t[i]>=2){
            isEmpty=false;
            cout<<setfill('0')<<setw(3)<<i/10000<<"-"<<setw(4)<<i%10000<<" "<<t[i]<<endl;
        }
    }
    if(isEmpty)cout<<"No duplicates."<<endl;
    return 0;
}