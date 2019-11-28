#include<iostream>
#include<string>
#include<sstream>
using namespace std;
string fruit[7]={"apples", "bananas", "peaches", "cherries", "pears", "oranges", "strawberries"};
int main(){
    string sentence;
    while(getline(cin,sentence)){
        bool isReplaced=false;
        for(int i=0;i<7;i++){
            int pos;
            while(pos=sentence.find(fruit[i]),pos!=string::npos){
                sentence.replace(pos,fruit[i].length(),"Brussels sprouts");
                isReplaced=true;
            }
        }
        if(isReplaced)cout<<sentence<<endl;
        else cout<<"You must not enjoy fruit."<<endl;
    }
    return 0;
}