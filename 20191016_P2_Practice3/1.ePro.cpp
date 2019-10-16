#include<iostream>
#include<iomanip>
using namespace std;
double reverse_of_factorial(int x){
    int fact=1;
    for(int i=1;i<=x;i++){
        fact*=i;
    }
    return 1./fact;
}
int main(){
    double res=1.;
    for(int i=1;i<=10;i++){
        res+=reverse_of_factorial(i);
    }
    cout<<fixed<<setprecision(6)<<res<<endl;
    return 0;
}