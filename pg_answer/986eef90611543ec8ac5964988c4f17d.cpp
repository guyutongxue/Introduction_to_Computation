#include<iostream>
#include<string>
using namespace std;
string dict[102];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dict[i];
    }
    int len=dict[1].length();
    while(m--){
        string dest;
        cin>>dest;
        while(dest!=""){
            if(dest.length()<len){
                cout<<"No"<<endl;
                goto next;
            }
            string sub=dest.substr(0,len);
            for(int i=1;i<=n;i++){
                if(dict[i]==sub){
                    dest.erase(0,len);
                    goto endOfASub;
                }
            }
            cout<<"No"<<endl;
            goto next;
            endOfASub:;
        }
        cout<<"Yes"<<endl;
        next:;
    }
    return 0;
}