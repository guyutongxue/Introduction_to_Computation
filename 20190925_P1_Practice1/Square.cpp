#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main(){
    string input,sx,sy;
    double x,y;
    cin>>input;
    int i=input.find(',');
    sx=input.substr(0,i);
    sy=input.substr(i+1,input.length()-i);
    stringstream ss;
    ss<<sx;
    ss>>x;
    ss.clear();
    ss<<sy;
    ss>>y;
    //cout<<x<<" "<<y<<endl;
    if(x>-1&&x<1&&y>-1&&y<1)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}