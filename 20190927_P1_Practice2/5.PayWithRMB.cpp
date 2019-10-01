#include<iostream>
using namespace std;
int notes[6]={100,50,20,10,5,1};
int main(){
    int w;
    cin>>w;
    for(int i=0;i<6;i++){
        cout<<(w/notes[i])<<endl;
        w%=notes[i];
    }
    return 0;
}