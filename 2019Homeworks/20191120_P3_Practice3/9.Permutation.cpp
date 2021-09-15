#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    char a[9];
    cin>>a;
    int n=strlen(a);
    do{
        cout<<a<<endl;
    }
    while(next_permutation(a,a+n));
    return 0;
}