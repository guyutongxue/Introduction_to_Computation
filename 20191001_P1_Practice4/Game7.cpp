#include<iostream>
#include<vector>
using namespace std;
bool a[102];//isOut
int n;
vector<int> v;
bool isOut(int x){
    if(x%7==0)return true;
    do{
        if(x%10==7)return true;
    }
    while(x/=10);
    return false;
}
void next(vector<int>::iterator& x){
    x++;
    if(x==v.end())x=v.begin();//Mind that the end() means the next address of the last element.
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    int i=1;
    vector<int>::iterator p=v.begin();
    while(v.size()!=0){
        //for(auto t : v){
        //    cout<<t<<" ";
        //}
        //cout<<"H: "<<i<<" P: "<<*p<<endl;
        if(isOut(i)){
            cout<<*p<<endl;
            v.erase(p);
            if(p==v.end())p=v.begin();//Here is the consideration of erasing last element of v.
        }
        else next(p);//Only find next when nothing to erase.
        i++;
    }
}