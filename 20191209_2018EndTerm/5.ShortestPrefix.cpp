#include<iostream>
#include<string>
using namespace std;
int main(){
    string list[1002];
    int n=0;
    while(getline(cin,list[n++]));
    for(int i=0;i<n;i++){
        for(int pos=0;pos<list[i].length();pos++){
            string pre=list[i].substr(0,pos);
            bool isDup=false;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(list[j].substr(0,pos)==pre){
                    isDup=true;
                    break;
                }
                
            }
            if(!isDup){
                cout<<list[i]<<" "<<pre<<endl;
                break;
            }
            if(pos==list[i].length()-1){
                cout<<list[i]<<" "<<list[i]<<endl;
                break;
            }
        }
    }
}