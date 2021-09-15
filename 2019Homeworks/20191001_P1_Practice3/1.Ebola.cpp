#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int death[32];
    memset(death,0,sizeof(death));
    int N,X,Y,K,n=0;
    cin>>N>>X>>Y>>K;
    n+=N;
    death[Y]=N;
    for(int i=2;i<=K;i++){
        n-=death[i];
        int today=n*X;
        death[i+Y-1]=today;
        n+=today;
    }
    cout<<n<<endl;
    return 0;
}