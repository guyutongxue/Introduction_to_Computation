#include<iostream>
using namespace std;
bool isUsed[5]={false,false,false,false,false};
int car[5];
void print(int x){
    cout<<car[1]<<endl;
    cout<<(char)(x+'A')<<endl;
}
int check(){
    bool state[4]={car[1]==2,
    car[1]==4,
    car[1]!=3,
    car[1]!=4};
    int res=0,num=0;
    for(int i=0;i<4;i++){
        if(state[i]){
            res=i;
            num++;
        }
    }
    if(num!=1)return 0;
    return res;
}
bool generate(int k){
    if(k>4){
        int t=check();
        if(t){
             print(t);
            return true;
        }
    }
    for(int i=1;i<=4;i++){
        if(!isUsed[i]){
            car[k]=i;
            isUsed[i]=true;
            if(generate(k+1))return true;
            isUsed[i]=false;
        }
    }
    return false;
}
int main(){
    generate(1);
}