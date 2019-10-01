#include<iostream>
using namespace std;
int main(){
float X,M,S;
	cin>>X>>M;
	S+=X;
	for(int i=2;i<=100;i++){
		X*=1.08;
		S+=X;
		M*=1.1;
		if(S>=M){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"Forget it."<<endl;
	return 0;
}
