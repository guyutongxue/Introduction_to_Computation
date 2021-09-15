#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
void exe(double*& a,double*& b,double*& c){
    if(*a>*b)swap(a,b);
    if(*b>*c)swap(b,c);
    if(*a>*b)swap(a,b);
}
int main(){
    char comma;
    double x,y,z;
    cin>>x>>comma>>y>>comma>>z;
    double* px=&x;
    double* py=&y;
    double* pz=&z;
    exe(px,py,pz);
    cout.setf(ios::fixed);
    if(floor(*px)!=*px)cout<<setprecision(2);
    else cout<<setprecision(0);
    cout<<*px<<',';
    if(floor(*py)!=*py)cout<<setprecision(2);
    else cout<<setprecision(0);
    cout<<*py<<',';
    if(floor(*pz)!=*pz)cout<<setprecision(2);
    else cout<<setprecision(0);
    cout<<*pz;
    return 0;
}