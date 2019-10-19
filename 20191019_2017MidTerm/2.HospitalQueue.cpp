#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Patient{
    int no;
    int serious;
    Patient(int x,int y){
        no=x;
        serious=y;
    }
    bool operator<(Patient b)const{
        return (this->serious==b.serious?
        this->no<b.no:
        this->serious>b.serious);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<Patient> p;
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int s;
            cin>>s;
            p.push_back(Patient(i,s));
        }
        sort(p.begin(),p.end());
        int m=min(n,k);
        cout<<m<<endl;
        for(int i=0;i<m;i++){
            cout<<p[i].no<<(i==m-1?"\n":" ");
        }
    }
    return 0;
}