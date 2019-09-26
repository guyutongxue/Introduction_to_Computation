#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int ticket[16];
    int n;
    memset(ticket,0,sizeof(ticket));
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        ticket[t]++;
    }
    int M=0,j=0;
    for(int i=1;i<=15;i++){
        if(ticket[i]>M){
            M=ticket[i];
            j=i;
        }
    }
    cout<<j<<endl;
    return 0;
}