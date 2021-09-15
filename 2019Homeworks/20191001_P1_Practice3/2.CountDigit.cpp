//5-7
#include<iostream>
#include<string>
using namespace std;
bool check(string p){
    return (2*'0'+p[3]-p[0]-p[1]-p[2]>0);
}
int main(){
    int n,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        string temp;
        cin>>temp;
        if(check(temp))cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}