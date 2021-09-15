#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
struct Coordinate{
    int x;
    int y;
    int value;
    Coordinate(int a,int b,int c){
        x=a,y=b,value=c;
    }
    bool operator<(Coordinate b)const{
        return value>b.value;
    }
    int operator-(Coordinate b)const{
        return abs(x-b.x)+abs(y-b.y);
    }
};
vector<Coordinate> v;
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n,k;
        cin>>m>>n>>k;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int s;
                cin>>s;
                if(s)v.push_back(Coordinate(i,j,s));
            }
        }
        sort(v.begin(),v.end());
        //for(auto p=v.begin();p!=v.end();p++)cout<<p->x<<" "<<p->y<<" "<<p->value<<endl;
        int time=v[0].x+1;
        int value=v[0].value;
        int res=value;
        int i;
        for(i=1;i<v.size();i++){
            time+=1+(v[i]-v[i-1]);
            value+=v[i].value;
            //cout<<value<<" "<<time<<endl;
            if(time+v[i].x>k)break;
            res=value;
        }
        cout<<res<<endl;
        v.clear();
    }
}