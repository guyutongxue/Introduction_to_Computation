#include<iostream>
#include<cstring>
using namespace std;
int a[24];
bool isVisit[24];
int n;
int next(int& x){
    if(isVisit[x]){
        x++;
        return 2;
    }
    isVisit[x]=true;
    if(a[x]==0){
        x++;
        return 2;
    }
    x+=a[x];
    if(x<0)x=0;
    if(x>n+1)x=n+1;
    return 1;
}
int main(){
    memset(isVisit,false,sizeof(isVisit));
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int c=1,s=1;
    while(c!=n+1){
        s+=next(c);
    }
    cout<<s<<endl;
    return 0;
}