#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
bool isPrime(int x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0)return false;
    }
    return true;
}
string factorize(int x){
    if(isPrime(x)){
        stringstream ss;
        ss<<x;
        string res;
        ss>>res;
        return res;
    }
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            stringstream ss;
            ss<<i;
            string res;
            ss>>res;
            return res+'*'+factorize(x/i);
        }
    }
}
int main(){
    string result;
    int n;
    cin>>n;
    cout<<n<<"="<<factorize(n)<<endl;
    return 0;
}