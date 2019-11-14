#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    for(int i=0;i<=11;i++){
        for(int j=0;j<=11;j++){
            if(a>>i==b>>j){
                cout<<(a>>i)<<endl;
                return 0;
            }
        }
    }
    return 0;
}