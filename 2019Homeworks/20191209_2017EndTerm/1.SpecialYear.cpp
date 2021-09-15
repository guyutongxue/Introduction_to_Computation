#include<iostream>
using namespace std;
bool judge(int x){
    int a=x%10;
    int b=x/10%10;
    int c=x/100%10;
    int d=x/1000;
    return a!=b&&a!=c&&a!=d&&b!=c&&b!=d&&c!=d;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        while(a++){
            if(judge(a)){
                cout<<a<<endl;
                break;
            }
        }
    }
}