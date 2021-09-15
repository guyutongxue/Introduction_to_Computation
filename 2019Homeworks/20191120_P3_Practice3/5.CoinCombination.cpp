#include<iostream>
#include<iomanip>
#include<string>
#include<stack>
#include<sstream>
using namespace std;
stack<string> s;
int money[4]={0,5,2,1};
int a[4];
int t=1;
void find(int x,int k){
    if(k==4){
        if(x==0){
            ostringstream st;
            for(int i=3;i>=1;i--){
                st<<setfill(' ')<<setw(12)<<a[i];
            }
            st<<endl;
            s.push(st.str());
        }
        return;
    }
    for(int i=x/money[k];i>=0;i--){
        a[k]=i;
        find(x-i*money[k],k+1);
    }
}
int main(){
    int x;
    cin>>x;
    find(x,1);
    while(!s.empty()){
        cout<<setfill('0')<<setw(3)<<t++<<s.top();
        s.pop();
    }
}