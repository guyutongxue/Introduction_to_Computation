// Same as P4-1/8
#include<iostream>
#include<cstring>
using namespace std;
int k1,k2,k3;
int main(){
    while(true){
        cin>>k1>>k2>>k3;
        cin.ignore();
        if(k1==0&&k2==0&&k3==0)return 0;
        char* p1[200];
        char* p2[200];
        char* p3[200];
        char i1[200];
        char i2[200];
        char i3[200];
        int index[200],n=0,n1=0,n2=0,n3=0;
        char c;
        for(int i=0;c=cin.get(),c!='\n';i++){
            if(c=='_')i3[n3++]=c,index[n++]=3;
            else if(c<='i')i1[n1++]=c,index[n++]=1;
            else if(c<='r')i2[n2++]=c,index[n++]=2;
            else i3[n3++]=c,index[n++]=3;
        }
        if(n1!=0)for(int i=0;i<=n1;i++)p1[i]=&i1[(i+100*n1-k1)%n1];
        if(n2!=0)for(int i=0;i<=n2;i++)p2[i]=&i2[(i+100*n2-k2)%n2];
        if(n3!=0)for(int i=0;i<=n3;i++)p3[i]=&i3[(i+100*n3-k3)%n3];
        int z1=0,z2=0,z3=0;
        for(int i=0;i<n;i++){
            if(index[i]==1)cout<<*(p1[z1++]);
            else if(index[i]==2)cout<<*(p2[z2++]);
            else cout<<*(p3[z3++]);
        }
        cout<<endl;
    }
}