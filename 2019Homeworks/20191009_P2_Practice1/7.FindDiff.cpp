#include<iostream>
#include<cstring>
using namespace std;
bool check[102];
int main(){
    int n;
    cin>>n;
    memset(check,false,sizeof(check));
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        check[w]=!check[w];
    }
    for(int i=1;i<=100;i++){
        if(check[i]){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}