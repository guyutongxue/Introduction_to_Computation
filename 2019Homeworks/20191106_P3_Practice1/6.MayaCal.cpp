#include<iostream>
#include<string>
using namespace std;
string HaabMonth[20]={"","pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
string TzolkinMonth[21]={"","imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int TransHMonth(string m){
    for(int i=1;i<=19;i++){
        if(HaabMonth[i]==m)return i;
    }
    return 0;
}
int main(){
    int t;
    cin>>t;
    cout<<t<<endl;
    while(t--){
        float Hday;
        string Hmonth;
        int Hyear;
        cin>>Hday>>Hmonth>>Hyear;
        int dates=Hyear*365+(TransHMonth(Hmonth)-1)*20+(int)Hday;
        cout<<dates%13+1<<" "<<TzolkinMonth[dates%20+1]<<" "<<dates/260<<endl;
    }
    return 0;
}