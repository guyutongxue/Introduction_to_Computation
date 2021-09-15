// Same as P1-4/5
#include<iostream>
#include<queue>
#include<sstream>
using namespace std;
queue<int> q[40];
int sum_of_digit(int x){
    int sum=0;
    do{
        sum+=(x%10);
    }
    while(x/=10);
    return sum;
}
int n,m,k;
string output[10002];
int main(){
    char what_the_fxxk_why_you_use_comma_as_separate_character;
    cin>>n>>what_the_fxxk_why_you_use_comma_as_separate_character>>m>>what_the_fxxk_why_you_use_comma_as_separate_character>>k;
    for(int i=n+1;i<m;i++){
        int s=sum_of_digit(i);
        if(s%k==0){
            q[s/k].push(i);
        }
    }
    for(int i=1;i<=10000;i++)output[i]="";//Initialize
    for(int i=1;i<40;i++){
        if(q[i].empty())continue;
        stringstream ss;
        int index=q[i].front();
        while(q[i].size()>1){
            ss<<q[i].front()<<",";
            q[i].pop();
        }
        ss<<q[i].front();
        ss>>output[index];//Use stringstream to build the output string, and store it in output[] in the order of first element.
    }
    for(int i=1;i<=10000;i++){
        if(output[i]=="")continue;
        cout<<output[i]<<endl;
    }
    return 0;
}