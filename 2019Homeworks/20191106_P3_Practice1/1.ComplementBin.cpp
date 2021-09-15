#include<iostream>
using namespace std;
int main(){
    int x;
    while(cin>>x){
        for(int i=31;i>=0;i--){
            cout<<bool((1<<i)&x);
        }
        cout<<endl;
    }
    return 0;
}