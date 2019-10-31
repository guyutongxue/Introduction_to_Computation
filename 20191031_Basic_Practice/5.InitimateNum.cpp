//I HATE THIS PROGRAM. ANYWAY.
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
bool primes[1000000];//ok ok ok
void init(){
    memset(primes,true,sizeof(primes));
    primes[1]=false;
    for(int i=2;i<=1000;i++){
        if(primes[i]){
            for(int j=2*i;j<=1000000;j+=i){
                primes[j]=false;
            }
        }
    }
}
int a,b;
int GetBase(int x){
    int res=1;
    for(int i=2;i<=x;i++){
        if(primes[x]||x==1){
            res*=x;
            return res;
        }
        if(primes[i]&&x%i==0){
            res*=i;
            do{
                x/=i;
            }
            while(x%i==0);
        }
    }
    return res;
}
int main(){
    init();
    char comma;
    cin>>a>>comma>>b;
    cout<<(GetBase(a)==GetBase(b)?"YES":"NO")<<endl;
    return 0;
}