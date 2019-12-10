#include<iostream>
#include<string>
using namespace std;
int target;
string src;
int n;
bool cutpoint[7];
int frag[7];
int res[7];
bool isError=true;
bool isReject=false;
int minn=-1;
int pfrag=0;
int pres=0;

void analyse(){
    pfrag=0;
    int start=0;
    for(int i=1;i<=n;i++){
        if(cutpoint[i]){
            frag[pfrag++]=atoi(src.substr(start,i-start).c_str());
            start=i;
        }
    }
    frag[pfrag++]=atoi(src.substr(start,n-start+1).c_str());
    int sum=0;
    for(int i=0;i<pfrag;i++){
        sum+=frag[i];
    }
    if(sum<=target){
        if(sum>minn){
            isError=false;
            isReject=false;
            minn=sum;
            memcpy(res,frag,sizeof(frag));
            pres=pfrag;
        }
        else if(sum==minn)isReject=true;
    }
}

void cut(int pos){
    if(pos>n){
        analyse();
        return;
    }
    cutpoint[pos]=false;
    cut(pos+1);
    cutpoint[pos]=true;
    cut(pos+1);
}



int main(){
    while(cin>>target>>src,target!=0||src!="0"){
        if(target==atoi(src.c_str())){
            cout<<src<<" "<<src<<endl;
            continue;
        }
        n=src.length()-1;
        isError=true;
        isReject=false;
        minn=-1;
        cut(1);
        if(isError)cout<<"error"<<endl;
        else if(isReject)cout<<"rejected"<<endl;
        else{
            cout<<minn<<" ";
            for(int i=0;i<pres;i++){
                cout<<res[i]<<(i==pres-1?"\n":" ");
            }
        }
    }
}