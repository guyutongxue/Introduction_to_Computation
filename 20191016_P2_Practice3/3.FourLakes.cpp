#include<iostream>
#include<cstring>
using namespace std;
char lake[6];
char sample[5]={0,'P','D','T','H'};
bool isUsed[256];
bool check(){
    bool A=
        (char)(lake[1]=='D')+
        (char)(lake[4]=='H')+
        (char)(lake[3]=='P')
        ==1;
    bool B=
        (char)(lake[1]=='H')+
        (char)(lake[4]=='D')+
        (char)(lake[2]=='P')+
        (char)(lake[3]=='T')
        ==1;
    bool C=
        (char)(lake[4]=='H')+
        (char)(lake[3]=='D')
        ==1;
    bool D=
        (char)(lake[1]=='P')+
        (char)(lake[4]=='T')+
        (char)(lake[2]=='H')+
        (char)(lake[3]=='D')
        ==1;
    return A&&B&&C&&D;
}
void print(){
    lake[6]='\0';
    //cout<<lake+1;
    for(int i=1;i<=4;i++){
        cout<<strchr(lake+1,sample[i])-lake<<endl;
    }
}
void generate(int k){
    if(k>4){
        if(check())
            print();
        return;
    }
    for(int i=1;i<=4;i++){
        if(!isUsed[sample[i]]){
            lake[k]=sample[i];
            isUsed[sample[i]]=true;
            generate(k+1);
            isUsed[sample[i]]=false;
        }
    }
}
int main(){
    memset(isUsed,false,sizeof(isUsed));
    generate(1);
    return 0;
}