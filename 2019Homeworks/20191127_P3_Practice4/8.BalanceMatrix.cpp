// Same as P3-3/2
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int m[9][9];
int trans[9];
int rmin;
inline int f(int x){
    if(x>n)return x-n;
    return x;
}
void search(int k){
    if(k==0){
        int rmax=-1;
        for(int j=1;j<=n;j++){
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=m[i][f(j+trans[i])];
            }
            rmax=max(rmax,sum);
        }
        rmin=min(rmin,rmax);
        return;
    }
    for(int i=0;i<n;i++){
        trans[k]=i;
        search(k-1);
    }
}
int main(){
    while(cin>>n,n!=-1){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>m[i][j];
            }
        }
        rmin=1<<20;
        search(n);
        cout<<rmin<<endl;
    }
    return 0;
}