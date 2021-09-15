#include<iostream>
using namespace std;
int a[202],b[202];
int main(){
    int n;
    cin>>n;
    int ca=0,cb=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i])ca++;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        if(b[i])cb++;
    }
    if(ca!=cb){
        cout<<-1<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i]==a[i])continue;
        int j=i;
        while(a[j]!=b[i])j++;
        while(j!=i){
            swap(a[j],a[j-1]);
            cnt++;
            j--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}