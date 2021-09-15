#include<iostream>
#include<string>
#include<sstream>
using namespace std;
bool isLeap(int y){
    return ((y%4==0&&y%100!=0)||y%400==0);
}
// Return which day of the week. 0 represent Sunday.
int getWeek(int y,int m,int d){
    int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int monthL[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
    int gap=0;
    for(int i=2000;i<y;i++){
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
    gap+=5;
    return gap%7;
}
bool check(string number,int week){
    if(number[5]>='A'&&number[5]<='Z'&&week==5)return false;
    if((number[5]=='5'||number[5]=='0')&&week==5)return false;
    if((number[5]=='4'||number[5]=='9')&&week==4)return false;
    if((number[5]=='3'||number[5]=='8')&&week==3)return false;
    if((number[5]=='2'||number[5]=='7')&&week==2)return false;
    if((number[5]=='1'||number[5]=='6')&&week==1)return false;
    return true;
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string date,number;
        int y,m,d;
        cin>>date>>number;
        stringstream ss;
        ss<<date.substr(0,4);ss>>y;ss.clear();
        ss<<date.substr(5,2);ss>>m;ss.clear();
        ss<<date.substr(8,2);ss>>d;ss.clear();
        int week=getWeek(y,m,d);
        //cout<<y<<" "<<m<<" "<<d<<" "<<week<<endl;
        cout<<(check(number,week)?"no":"yes")<<endl;
    }
    return 0;
}