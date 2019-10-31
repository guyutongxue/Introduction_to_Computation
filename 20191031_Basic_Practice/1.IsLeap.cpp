#include<iostream>
using namespace std;
bool isLeap(int y){
    return ((y%4==0&&y%100!=0)||y%400==0);
}
int main(){
    int n;
    cin>>n;
    cout<<(isLeap(n)?"Y":"N")<<endl;
    return 0;
}