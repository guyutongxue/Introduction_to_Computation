#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
/**
 * I don't know what is 'Newton's Method'.
 * So I copied this function from:
 * https://www.cnblogs.com/qlky/p/7735145.html
 * I will try to understand it later.
*/
double n_sqrt(double x,int& cnt) {
    if(x==0)return 0;
    double last=0.;
    double res=1.;
    while(abs(res-last)>=1e-6){
        last=res;
        res=(res+x/res)/2;
        cnt++;
    }
    return res;
}

int main(){
    int n;
    while(cin>>n){
        int cnt=0;
        double res=n_sqrt(n,cnt);
        cout.unsetf(ios_base::floatfield);
        cout<<cnt<<" "
        <<setprecision(2)<<fixed<<res<<endl;
    }
}