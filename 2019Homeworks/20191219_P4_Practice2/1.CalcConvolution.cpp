#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
T at(T* array,int index,int range){
    if(index>=range||index<0)return (T)0;
    else return array[index];
}

int a[32],b[32];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        for(int i=0;i<m+n-1;i++){
            int res=0;
            for(int j=-99;j<=99;j++){
                res+=(at(a,j,n)*at(b,i-j,m));
            }
            cout<<res<<" \n"[i==m+n-2];
        }
    }
}