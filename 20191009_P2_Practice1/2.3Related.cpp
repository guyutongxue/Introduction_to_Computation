#include<iostream>
using namespace std;
bool isOut(int x){
    if(x%3==0)return true;
    do{
        if(x%10==3)return true;
    }
    while(x/=10);
    return false;
}
int main(){
    int n;
    while(cin>>n){
        cout<<(isOut(n)?"TRUE":"FALSE")<<endl;
    }
}