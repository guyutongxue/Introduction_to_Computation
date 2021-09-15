#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
struct Dive{
    int id;
    double rate;
    bool operator<(Dive y)const{
        return rate<y.rate;
    }
};
Dive a[101];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int no,origin,now;
        cin>>no>>origin>>now;
        a[i].id=no;
        a[i].rate=1.*now/origin;
    }
    sort(a+1,a+n+1);
    double maxRate=0;
    int sep=1;
    for(int i=2;i<=n;i++){
        if(maxRate<a[i].rate-a[i-1].rate){
            sep=i-1;
            maxRate=a[i].rate-a[i-1].rate;
        }
    }
    cout<<n-sep<<endl;
    for(int i=sep+1;i<=n;i++){
        cout<<a[i].id<<endl;
    }
    cout<<sep<<endl;
    for(int i=1;i<=sep;i++){
        cout<<a[i].id<<endl;
    }
    return 0;
}