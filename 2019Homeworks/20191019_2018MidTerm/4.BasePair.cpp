#include<iostream>
#include<string>
using namespace std;
void ppair(char& c){
    if(c=='A')c='T';
    else if(c=='T')c='A';
    else if(c=='C')c='G';
    else if(c=='G')c='C';
}
int main(){
    int n;
    cin>>n;
    while(n--){
        string dna;
        cin>>dna;
        for(int i=0;i<dna.length();i++)
            ppair(dna[i]);
        cout<<dna<<endl;
    }
    return 0;
}