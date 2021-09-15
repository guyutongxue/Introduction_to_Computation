#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>

using namespace std;

#ifdef USE_STRINGSTREAM

int main(){
    ios::sync_with_stdio(false);
    while(true){
        string input;
        cin>>input;
        if(input=="q")break;
        for(int i=0;i<input.length();i++){
            if((input[i]<'0'||input[i]>'9')&&input[i]!='+'&&input[i]!='-'&&input[i]!='.')input[i]='e';

        }
        stringstream ss;
        ss<<input;
        double d;
        ss>>d;
        cout<<fixed<<setprecision(6)<<d<<endl;
    }
    return 0;
}

#else

double multiplyer=1;

void dot(double& res,char s){
    res+=(multiplyer*(s-'0'));
}

void add(double& res,char s){
    (res*=10)+=(s-'0');
}

void add_int(int& res,char s){
    (res*=10)+=(s-'0');
}

int main(){
    ios::sync_with_stdio(false);
    while(true){
        string str;
        cin>>str;
        if(str=="q")break;
        double res=0;
        string E="0";
        for(int i=0;i<str.length();i++){
            if((str[i]<'0'||str[i]>'9')&&str[i]!='+'&&str[i]!='-'&&str[i]!='.'){
                E=str.substr(i+1,str.length()-i-1);
                str=str.substr(0,i);
            }
        }
        void(* deal)(double&,char)=NULL;
        bool isDot=false;
        multiplyer=1;
        int pm=1;
        for(int p=0;p<str.length();p++){
            deal=add;
            if(str[p]=='+'||str[p]=='-'){
                pm=(str[p]=='+'?1:-1);
                continue;
            }
            else if(str[p]=='.'){
                isDot=true;
                continue;
            }
            if(isDot)deal=dot,multiplyer/=10;
            deal(res,str[p]);
        }
        int resE=0;
        int pmE=1;
        for(int p=0;p<E.length();p++){
            if(E[p]=='+'||E[p]=='-'){
                pmE=(E[p]=='+'?1:-1);
                continue;
            }
            add_int(resE,E[p]);
        }
        cout<<fixed<<setprecision(6)<<pm*res*pow(10.,pmE*resE)<<endl;
    }
    return 0;
}

#endif