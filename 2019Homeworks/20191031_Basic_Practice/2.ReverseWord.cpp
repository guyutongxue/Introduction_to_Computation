#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str="",space="";
    bool flag=false;
    while(true){
        char x=cin.get();
        if(x>='A'&&x<='Z'||x>='a'&&x<='z'||x=='!'){
            if(str==""){
                cout<<space;
                space.clear();
            }
            str+=x;
        }
        else{
            if(space==""){
                reverse(str.begin(),str.end());
                cout<<str;
                str.clear();
            }
            space+=' ';
        }
        if(cin.eof())break;
    }
    return 0;
}