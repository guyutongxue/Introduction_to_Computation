#include<iostream>
#include<cstring>
using namespace std;
bool a[152];
int main(){
    memset(a,false,sizeof(a));
    for(int i=1;i<=150;i++){
        for(int j=i;j<=150;j+=i){
            a[j]^=true;
        }
    }
    bool isFirst=true;
    int cnt=0;
    for(int i=1;i<=150;i++){
        if(a[i]){
            if(isFirst){
                cout<<"N"<<i;
                isFirst=false;
            }
            else cout<<" N"<<i;
            cnt++;
        }
    }
    cout<<endl<<cnt<<endl;
    return 0;
}