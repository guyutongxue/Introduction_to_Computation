#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<iomanip>
using namespace std;
bool isKnown[129];
string value[129];
double parseValue(string x){
    stringstream ss(x);
    double res;
    ss>>res;
    if(x.find('m')!=string::npos)res*=1e-3;
    if(x.find('k')!=string::npos)res*=1e3;
    if(x.find('M')!=string::npos)res*=1e6;
    return res;
}
int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int t=1;t<=n;t++){
        memset(isKnown,false,sizeof(isKnown));
        string question;
        getline(cin,question);
        for(int i=0;i<=question.length();i++){
            if(question[i]!='=')continue;
            isKnown[question[i-1]]=true;
            int j=0;while(question[i+j]!=' ')j++;
            value[question[i-1]]=question.substr(i+1,j);
        }
        cout.unsetf(ios::floatfield);
        cout<<"Problem #"<<t<<endl;
        cout.setf(ios::fixed);
        cout.precision(2);
        if(isKnown['I']&&isKnown['U']){
            cout<<"P="<<parseValue(value['I'])*parseValue(value['U'])<<"W"<<endl<<endl;
        }
        else if(isKnown['I']&&isKnown['P']){
            cout<<"U="<<parseValue(value['P'])/parseValue(value['I'])<<"V"<<endl<<endl;
        }
        else if(isKnown['P']&&isKnown['U']){
            cout<<"I="<<parseValue(value['P'])/parseValue(value['U'])<<"A"<<endl<<endl;
        }
        
    }
    return 0;
}