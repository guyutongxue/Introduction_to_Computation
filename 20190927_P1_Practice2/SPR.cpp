#include<iostream>
#include<algorithm>
using namespace std;
int r[2]={0,0};
int match(int x,int y){
    if((x==2&&y==0)||(x==0&&y==1)||(x==1&&y==2))return 0;
    else if(x==y)return 2;
    else return 1;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        r[match(x,y)]++;
    }
    cout<<(r[0]>r[1]?"A":(r[0]==r[1]?"Tie":"B"))<<endl;
}