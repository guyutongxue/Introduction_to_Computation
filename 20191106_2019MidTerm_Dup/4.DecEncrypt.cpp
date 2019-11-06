#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int m[12][12];
bool f[12][12];
void next(int& x,int& y,int& p){
    switch(p){
        case 1:{
            if(f[x][y+1]){
                p++;
                x++;
            }
            else{
                y++;
            }
            break;
        }
        case 2:{
            if(f[x+1][y]){
                p++;
                y--;
            }
            else{
                x++;
            }
            break;
        }
        case 3:{
            if(f[x][y-1]){
                p++;
                x--;
            }
            else{
                y--;
            }
            break;
        }
        case 4:{
            if(f[x-1][y]){
                p=1;
                y++;
            }
            else{
                x--;
            }
            break;
        }
    }
}
int parse(char x,int pos){
    int res=(x==' '?0:x-'A'+1);
    if(pos==1)return res/10;
    else return res%10;
}
int R,C;
char text[52];
int main(){
    cin>>R>>C;
    cin.ignore();
    cin.getline(text,52);
    memset(m,0,sizeof(m));
    memset(f,false,sizeof(f));
    for(int i=0;i<=max(R,C)+1;i++){
        f[R+1][i]=f[i][C+1]=f[0][i]=f[i][0]=true;
    }
    int x=1,y=1,p=1;
    for(int i=0;i<strlen(text);i++){
        m[x][y]=parse(text[i],1);
        f[x][y]=true;
        next(x,y,p);
        m[x][y]=parse(text[i],2);
        f[x][y]=true;
        next(x,y,p);
    }
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cout<<m[i][j];
        }
    }
    return 0;
}