#include<iostream>
using namespace std;
bool isOut(int x){
    if(x%4==0)return true;
    do{
        if(x%10==4)return true;
    }
    while(x/=10);
    return false;
}
int main(){
    int n,sum=0;
    cin>>n;
    //i is the number of patient; j is how many patient now.
    for(int i=1,j=1;j<=n;i++){
        if(isOut(i)){
            continue;
        }
        sum+=i;
        j++;
    }
    cout<<sum<<endl;
    return 0;
}