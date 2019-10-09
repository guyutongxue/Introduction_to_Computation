#include<iostream>
#include<iomanip>
using namespace std;
const double PI=3.14159;
int main(){
    double r,h;
    cin>>r>>h;
    cout<<"Area = "<<fixed<<setprecision(3)<<(2*PI*r*(r+h))<<endl;
    return 0;
}