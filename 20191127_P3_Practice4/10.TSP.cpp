#include <iostream>
using namespace std;
int n;
int a[17][17];
int x[17];
int best=1<<30;
int sum;
void search(int k){
    if(k>n){
       if(x[n]!=x[1]&&(sum+a[x[n]][x[1]])<best)
           best=sum+a[x[n]][x[1]];
       return;
    }
    for(int i=k;i<=n;i++){
       if(x[k-1]!=x[i]&&(sum+a[x[k-1]][x[i]])<best){
           swap(x[k],x[i]);
           sum+=a[x[k-1]][x[k]] ;
           search(k+1);
           sum-=a[x[k-1]][x[k]];
           swap(x[i],x[k]);
       }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++)
           cin>>a[i][j];
    sum=0;
    for(int i=1;i<=n;i++)
       x[i]=i;
    search(2);
    cout<<best<<endl;
    return 0;
}