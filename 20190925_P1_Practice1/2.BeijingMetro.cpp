#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double off(int sum,int origin){
    if(sum<100||sum>=400)return 1.*origin;
    else if(sum<150)return origin*0.8;
    else return origin*0.5;
}


int main(){
    int sum,x,w=0;
    cin>>sum>>x;
    if(x<=6)w=3;
    else if(x<=12)w=4;
    else if(x<=32)w=4+ceil(1.*(x-12)/10);
    else w=6+ceil(1.*(x-32)/20);
    printf("%.2f\n",off(sum,w));
}