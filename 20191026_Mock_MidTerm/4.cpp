#include<iostream>
#include<cstring>
using namespace std;
int tie_n[10][10];
int tie[10][10];
int tie_o[10][10];
void gen(int x,int y){
    int b=tie[x][y];
    if(x!=1){
        if(y!=1)tie_n[x-1][y-1]+=b;
        tie_n[x-1][y]+=b;
        if(y!=9)tie_n[x-1][y+1]+=b;
    }
    if(y!=1)tie_n[x][y-1]+=b;
    tie_n[x][y]+=2*b;
    if(y!=9)tie_n[x][y+1]+=b;
    if(x!=9){
        if(y!=1)tie_n[x+1][y-1]+=b;
        tie_n[x+1][y]+=b;
        if(y!=9)tie_n[x+1][y+1]+=b;
    }
}
int main(){
    int n;
    memset(tie,0,sizeof(tie));
    memset(tie_n,0,sizeof(tie_n));
    memset(tie_o,0,sizeof(tie));
    cin>>tie[5][5]>>n;
    while(n--){
        for(int i=1;i<=9;i++){
            for(int j=1;j<=9;j++){
                gen(i,j);
            }
        }
        //for(int i=1;i<=9;i++){
        //    for(int j=1;j<=9;j++){
        //        tie_n[i][j]-=tie_o[i][j];
        //    }
        //}
        //memcpy(tie_o,tie,sizeof(tie));
        memcpy(tie,tie_n,sizeof(tie_n));
        memset(tie_n,0,sizeof(tie_n));
    }
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            cout<<tie[i][j]<<(j==9?"\n":" ");
        }
    }
    return 0;
}