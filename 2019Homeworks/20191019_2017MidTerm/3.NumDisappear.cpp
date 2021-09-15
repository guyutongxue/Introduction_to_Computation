#include<iostream>
#include<cstring>
using namespace std;
bool a[102];
int main(){
    int n;
    cin>>n;
    memset(a,false,sizeof(a));
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        a[w]=true;
    }
    for(int i=1;i<=n;i++){
        if(a[i])continue;
        cout<<i<<endl;
    }
    return 0;
}