//Same as P2-2/5
#include<iostream>
#include<algorithm>
using namespace std;
struct Docter{
    int no;
    int cnt;
};
bool comp(Docter a,Docter b){
    return (a.cnt==b.cnt?a.no<b.no:a.cnt<b.cnt);
}
Docter d[102];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        d[i].no=i;
        int c;
        cin>>c;
        d[i].cnt=c;
    }
    sort(d+1,d+n+1,comp);
    cout<<d[1].no<<endl;
    return 0;
}