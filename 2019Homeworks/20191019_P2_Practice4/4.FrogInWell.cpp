#include<iostream>
using namespace std;
int main(){
    int H,U,D;
    int h=0,i=0;
    cin>>H>>U>>D;
    while(true){
        i++;
        h+=U;
        if(h>=H)break;
        h-=D;
    }
    cout<<i<<endl;
    return 0;
}