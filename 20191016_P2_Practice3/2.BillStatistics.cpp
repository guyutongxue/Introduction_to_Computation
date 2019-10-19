#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
double pv[4];
double tv[4];
int main(){
    memset(pv,0,sizeof(pv));
    memset(tv,0,sizeof(tv));
    for(int i=1;i<=3;i++){
        int p,n;
        cin>>p>>n;
        for(int i=1;i<=n;i++){
            char t;
            double v;
            cin>>t>>v;
            pv[p]+=v;
            tv[t-'A']+=v;
        }
    }
    for(int i=1;i<=3;i++){
        cout.unsetf(ios_base::floatfield);
        cout<<i<<" "<<fixed<<setprecision(2)<<pv[i]<<endl;
    }
    for(int i=0;i<3;i++){
        cout.unsetf(ios_base::floatfield);
        cout<<(char)('A'+i)<<" "<<fixed<<setprecision(2)<<tv[i]<<endl;
    }
    return 0;
}