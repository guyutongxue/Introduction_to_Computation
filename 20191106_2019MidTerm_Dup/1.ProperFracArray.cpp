#include<iostream>
#include<algorithm>
using namespace std;
struct Fraction{
    int son;
    int parent;
    bool operator<(Fraction b)const{
        return son==b.son?parent<b.parent:son<b.son;
    }
};
Fraction f[4000];
int GCD(int a,int b){
    if(a<b)swap(a,b);
    int r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
int a[202];
int main(){
    int n,fn=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[i]==0||a[j]==0)continue;
            if(GCD(a[i],a[j])==1){
                fn++;
                f[fn].son=min(a[i],a[j]);
                f[fn].parent=max(a[i],a[j]);
            }
        }
    }
    sort(f+1,f+fn+1);
    if(fn!=0){
        cout<<f[1].son<<"/"<<f[1].parent;
        for(int i=2;i<=fn;i++){
            cout<<","<<f[i].son<<"/"<<f[i].parent;
        }
    }
    else cout<<"NO";
    return 0;
}