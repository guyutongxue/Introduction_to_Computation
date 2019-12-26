#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
struct Node{
    double x;
    double y;
    double z;
    Node(){}
    Node(int x,int y,int z){
        this->x=x;
        this->y=y;
        this->z=z;
    }
};
struct Distance{
    Node ln;
    Node rn;
    double value;
    Distance(Node a,Node b){
        ln=a;
        rn=b;
        value=sqrt(
            (ln.x-rn.x)*(ln.x-rn.x)+
            (ln.y-rn.y)*(ln.y-rn.y)+
            (ln.z-rn.z)*(ln.z-rn.z)
        );
    }
    bool operator<(Distance b)const{
        return value>b.value;
    }
    void print(){
        printf("(%.0lf,%.0lf,%.0lf)-(%.0lf,%.0lf,%.0lf)=%.2lf\n",ln.x,ln.y,ln.z,rn.x,rn.y,rn.z,value);
    }
};

vector<Distance> v;
Node nodes[12];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        double x,y,z;
        cin>>x>>y>>z;
        nodes[i]=Node(x,y,z);
        for(int j=1;j<i;j++){
            v.push_back(Distance(nodes[j],nodes[i]));
        }
    }
    stable_sort(v.begin(),v.end());
    for(vector<Distance>::iterator i=v.begin();i!=v.end();i++){
        i->print();
    }
    return 0;
}