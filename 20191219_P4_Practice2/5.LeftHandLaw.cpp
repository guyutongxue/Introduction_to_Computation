#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

char a[102][102];
bool mk[102][102][256];
int n,m;
bool isFound=false;

struct Position{
    char pos;
    Position(char c){pos=c;}
    Position operator-(int x){
        char res=pos;
        for(int i=1;i<=x;i++){
            switch(res){
                case 'E':res='N';break;
                case 'N':res='W';break;
                case 'W':res='S';break;
                case 'S':res='E';break;
            }
        }
        return Position(res);
    }
    Position operator+(int x){
        char res=pos;
        for(int i=1;i<=x;i++){
            switch(res){
                case 'E':res='S';break;
                case 'S':res='W';break;
                case 'W':res='N';break;
                case 'N':res='E';break;
            }
        }
        return Position(res);
    }
};


void step(Position p,int& x,int& y){
    switch(p.pos){
        case 'E':y++;break;
        case 'S':x++;break;
        case 'W':y--;break;
        case 'N':x--;break;
    }
}

void debug(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int res=0;
            if(mk[i][j]['N'])res+=1;
            if(mk[i][j]['E'])res+=2;
            if(mk[i][j]['S'])res+=4;
            if(mk[i][j]['W'])res+=8;
            cout<<hex<<res;
        }
        cout<<endl;
    }
    cout<<endl;
    
}
bool search(int x,int y,Position p){
    step(p,x,y);
    //debug();
    if(a[x][y]=='#')return false;
    if(a[x][y]=='T'){
        isFound=true;
        return true;
    }
    if(mk[x][y][p.pos])return true;
    mk[x][y][p.pos]=true;
    debug();
    return search(x,y,p-1)||search(x,y,p)||search(x,y,p+1)||search(x,y,p+2);
}
int main(){
    freopen("a.txt","w",stdout);
    while(cin>>n>>m){
        memset(mk,false,sizeof(mk));
        int x,y;
        char c;
        //if(n==26&&m==32)while(c=cin.get(),c!=EOF)cout<<(c=='\n'?'\\':c);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>a[i][j];
                if(a[i][j]=='S'){
                    x=i;
                    y=j;
                    a[i][j]='.';
                }
            }
        }
        cin.ignore();
        char dir;
        cin>>dir;
        Position p(dir);
        mk[x][y][dir]=true;
        isFound=false;
        search(x,y,p-1)||search(x,y,p)||search(x,y,p+1)||search(x,y,p+2);
        cout<<(isFound?"YES":"NO")<<endl;
    }
    return 0;
}