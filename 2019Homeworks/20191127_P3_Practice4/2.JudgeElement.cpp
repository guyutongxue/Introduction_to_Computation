#include<iostream>
using namespace std;
int k;
bool judge(int x){
    return x==k||((x-1)%2==0&&judge((x-1)/2))||((x-1)%3==0&&judge((x-1)/3));
}
int main(){
    int n;
    char comma;
    cin>>k>>comma>>n;
    cout<<(judge(n)?"YES":"NO")<<endl;
    return 0;
}