#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Pillar{
    int h;
    int no;
    bool operator<(Pillar b)const{
        return (this->h==b.h?
        this->no<b.no:
        this->h<b.h);
    }
};
Pillar p[20002];

int ffind(int a,int b){
    if(a==b)return p[a].h;
    if(a>b)return 0;
    Pillar mmin=p[a];
    for(int i=a+1;i<=b;i++){
        if(p[i]<mmin){
            mmin=p[i];
        }
    }
    //cout<<a<<" "<<mmin.no<<" "<<b<<endl;
    return max(mmin.h*(b-a+1),max(ffind(a,mmin.no-1),ffind(mmin.no+1,b)));
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i].h;
        p[i].no=i;
    }
    cout<<ffind(1,n)<<endl;
    return 0;
}