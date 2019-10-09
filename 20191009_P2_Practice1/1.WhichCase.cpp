#include<iostream>
using namespace std;
char* result(char x){
    if(x>='A'&&x<='Z')return "upper case";
    if(x>='a'&&x<='z')return "lower case";
    else return "invalid input";
}
int main(){
    char a;
    cin>>a;
    cout<<result(a)<<endl;
    return 0;
}