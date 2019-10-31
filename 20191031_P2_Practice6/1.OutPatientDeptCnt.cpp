//Same as P2-4/5
#include<iostream>
#include<cstring>
using namespace std;
int arrival[1000];
int main(){
    memset(arrival,0,sizeof(arrival));
    int n;
    int cnt=0;
    int qcnt=0;
    int cd=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int w;
        cin>>w;
        arrival[w]++;
    }
    for(int i=0;i<=179;i++){
        if(arrival[i])qcnt+=arrival[i];
        if(i>=60){
            if(cd==0&&qcnt!=0){
                qcnt--;
                cnt++;
                cd=10;
            }
            if(cd!=0)cd--;
        }
    }
    if(cd!=0)cnt--;
    cout<<cnt<<endl;
    return 0;
}