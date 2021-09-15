#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int minx=1<<30,miny=1<<30,maxx=-1,maxy=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int t;
            cin>>t;
            if(t==0){
                minx=min(minx,i);
                miny=min(miny,j);
                maxx=max(maxx,i);
                maxy=max(maxy,j);
            }
        }
    }
    cout<<(maxx-minx-1)*(maxy-miny-1)<<endl;
    return 0;
}