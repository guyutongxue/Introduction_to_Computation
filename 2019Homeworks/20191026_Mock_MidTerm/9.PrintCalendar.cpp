#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int monthL[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
bool isLeap(int y){
    return ((y%4==0&&y%100!=0)||y%400==0);
}
int getWeek(int y,int m,int d){
    
    int gap=0;
    for(int i=1900;i<y;i++){
        if(isLeap(i))gap+=366;
        else gap+=365;
    }
    if(isLeap(y)){
        for(int i=1;i<m;i++){
            gap+=monthL[i];
        }
    }
    else{
        for(int i=1;i<m;i++){
            gap+=month[i];
        }
    }
    gap+=d;
    //gap+=5;
    return gap%7;
}
int main(){
    int y,m;
    cin>>y>>m;
    int week=getWeek(y,m,1);
    cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
    for(int i=0;i<week;i++)cout<<"    ";
    for(int i=1;i<=(isLeap(y)?monthL[m]:month[m]);i++){
        cout<<setw(4)<<i;
        week++;
        if(week==7){
            week=0;
            cout<<endl;
        }
    }
    return 0;
}