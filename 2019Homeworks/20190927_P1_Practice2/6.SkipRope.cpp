#include<iostream>
#include<cstring>
using namespace std;
bool isBad[102];
int main(){
    int n;
    cin>>n;
    memset(isBad,false,sizeof(isBad));
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        isBad[w]=true;
    }
    int t=0,j=0;
    while(t<60){
        j++;
        t+=(isBad[j]?4:1);
    }
    cout<<j<<endl;
    return 0;
}