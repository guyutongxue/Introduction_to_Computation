#include<iostream>
#include<sstream>
#include<cmath>
using namespace std;
bool isPrime(int n){
    if(n<=1)return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)return false;
    }
    return true;
}


bool judge(int x){
    if(!isPrime(x/1000000))return false;
    double sq=sqrt(x%1000);
    if(floor(sq)!=sq||sq==0)return false;
    stringstream ss;
    ss<<x;
    string o=ss.str();
    return o.find("13")==string::npos;
}
int main(){
    int m,n;
    cin>>m>>n;
    int cnt=0;
    for(int i=m;i<=n;i++){
        if(judge(i))cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}