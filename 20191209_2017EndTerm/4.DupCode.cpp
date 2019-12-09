// Same as P4-1/7
#include<iostream>
#include<string>
using namespace std;
int main(){
    int a1=0,a2=0;
    int b1=0,b2=0;
    int la;
    cin>>la;
    cin.ignore();
    while(la--){
        string line;
        getline(cin,line);
        size_t pos;
        while(pos=line.find("if "),pos!=string::npos){
            a1++;
            line.erase(pos,3);
        }
        while(pos=line.find("switch "),pos!=string::npos){
            a1++;
            line.erase(pos,7);
        }
        while(pos=line.find("for "),pos!=string::npos){
            a2++;
            line.erase(pos,4);
        }
        while(pos=line.find("while "),pos!=string::npos){
            a2++;
            line.erase(pos,6);
        }
    }
    int lb;
    cin>>lb;
    cin.ignore();
    while(lb--){
        string line;
        getline(cin,line);
        size_t pos;
        while(pos=line.find("if "),pos!=string::npos){
            b1++;
            line.erase(pos,3);
        }
        while(pos=line.find("switch "),pos!=string::npos){
            b1++;
            line.erase(pos,7);
        }
        while(pos=line.find("for "),pos!=string::npos){
            b2++;
            line.erase(pos,4);
        }
        while(pos=line.find("while "),pos!=string::npos){
            b2++;
            line.erase(pos,6);
        }
    }
    cout<<((a1==b1&&a2==b2)?"Yes":"No")<<endl;
    return 0;
}