#include<iostream>
#include<algorithm>
using namespace std;
int a[1002],b[1002];
int main(){
    int n;
    while(cin>>n,n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int sum=0;
        int ag=n,bg=n;
        int al=1,bl=1;
        do{
            if(a[ag]>b[bg])ag--,bg--,sum++;
            else if(a[al]>b[bl])al++,bl++,sum++;
            else{
                if(a[al]<b[bg])sum--;
                else if(a[al]>b[bg])sum++;
                al++,bg--;
            }
        }
        while(al!=ag);
        if(a[al]>b[bl])sum++;
        else if(a[al]<b[bl])sum--;
        cout<<sum*200<<endl;
    }
}