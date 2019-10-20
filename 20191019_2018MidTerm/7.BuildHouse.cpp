#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
bool matrix[22][22];
int m,n;
struct Point{
    int x;
    int y;
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};
bool isOK(Point a,Point b){
    for(int i=a.x;i<=b.x;i++){
        for(int j=a.y;j<=b.y;j++){
            if(matrix[i][j])return false;
        }
    }
    return true;
}
int getArea(Point a,Point b){
    if(isOK(a,b))return (1+abs(a.x-b.x))*(1+abs(a.y-b.y));
    return 0;
}

int main(){
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cin>>matrix[i][j];
        }
    }
    int mmax=0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int k=i;k<=m;k++){
                for(int l=j;l<=n;l++){
                    mmax=max(mmax,getArea(Point(i,j),Point(k,l)));
                    //cout<<mmax<<endl;
                }
            }
        }
    }
    cout<<mmax<<endl;
    return 0;
}