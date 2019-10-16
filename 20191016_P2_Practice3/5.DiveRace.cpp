#include<iostream>
#include<cstring>
using namespace std;
int a[6];//a[athlete]=rank
bool isUsed[6];
bool check(){
    bool A=
        (char)(a[2]==2)+
        (char)(a[1]==3)
        ==1;
    bool B=
        (char)(a[2]==2)+
        (char)(a[5]==4)
        ==1;
    bool C=
        (char)(a[3]==1)+
        (char)(a[4]==2)
        ==1;
    bool D=
        (char)(a[3]==5)+
        (char)(a[4]==3)
        ==1;
    bool E=
        (char)(a[5]==4)+
        (char)(a[1]==1)
        ==1;    
    return A&&B&&C&&D&&E;
}
void print(){
    for(int i=1;i<=5;i++){
        cout<<a[i]<<endl;
    }
}
void generate(int k){
    if(k>5){
        if(check())
            print();
        return;
    }
    for(int i=1;i<=5;i++){
        if(!isUsed[i]){
            a[k]=i;
            isUsed[i]=true;
            generate(k+1);
            isUsed[i]=false;
        }
    }
}
int main(){
    memset(isUsed,false,sizeof(isUsed));
    generate(1);
    return 0;
}