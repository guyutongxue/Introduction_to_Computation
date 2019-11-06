#include<iostream>
#include<algorithm>
using namespace std;
void game(int a,int b,bool isFirst){
    if(a==0||b==0){
        cout<<(isFirst?"lose":"win")<<endl;
        return;
    }
    if(a<b)swap(a,b);
    if(a/b>=2){
        cout<<(isFirst?"win":"lose")<<endl;
        return;
    }
    game(a-b,b,!isFirst);
}
int main(){
    int a,b;
    while(cin>>a>>b,a*a+b*b){
        if(a<b)swap(a,b);
        game(a,b,true);
    }
    return 0;
}