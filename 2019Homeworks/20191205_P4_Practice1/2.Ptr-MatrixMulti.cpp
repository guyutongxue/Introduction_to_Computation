#include<cstdio>
using namespace std;

#define N 102

template<typename T>
T* at(T(* matrix)[N],T x,T y){
    return (T*)matrix+x*N+y;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int A[N][N];
        int B[N][N];
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",at(A,i,j));
            }
        }
        for(int j=1;j<=m;j++){
            for(int l=1;l<=k;l++){
                scanf("%d",at(B,j,l));
            }
        }
        for(int i=1;i<=n;i++){
            for(int l=1;l<=k;l++){
                int res=0;
                for(int j=1;j<=m;j++){
                    res+=(*at(A,i,j))*(*at(B,j,l));
                }
                //printf("here\n");
                printf("%d%c",res,*(" \n"+(l==k)));
            }
        }
    }
}