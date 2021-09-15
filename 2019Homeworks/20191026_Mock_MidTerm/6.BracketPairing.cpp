#include<iostream>
#include<stack>//I USE IT! COME ON DUDE!!
#include<string>
#include<algorithm>
using namespace std;
struct Bracket{
    int left;
    int right;
    bool operator<(Bracket b)const{
        return (right-left==b.right-b.left?left<b.left:right-left<b.right-b.left);
    }
};
stack<Bracket> s;
Bracket arr[252];
int parr=0;
int main(){
    basic_string<char> str;
    cin>>str;
    int d=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='('){
            Bracket b;
            b.left=i;
            b.right=-1;
            s.push(b);
        }
        if(str[i]==')'){
            if(s.empty()){
                cout<<"mismatch"<<endl;
                return 0;
            }
            Bracket b=s.top();
            s.pop();
            b.right=i;
            arr[++parr]=b;
        }
    }
    if(!s.empty()){
        cout<<"mismatch"<<endl;
        return 0;
    }
    sort(arr+1,arr+parr+1);
    if(parr==0){
        cout<<"0,0"<<endl;
        return 0;
    }
    for(int i=1;i<=parr;i++){
        cout<<arr[i].left+1<<","<<arr[i].right+1<<endl;
    }
    return 0;
}