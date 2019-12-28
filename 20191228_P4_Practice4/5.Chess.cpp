#include<iostream>
#include<cstring>
using namespace std;
int a[1010][16][16];
int Contest[1010][2];
int n;
void init(){
	n=1;
	while(cin>>Contest[n][0]){
		cin>> Contest[n][1];
		n++;
	}
	n--;
}
void solve(){
	memset(a,0,sizeof(a));
	a[1][1][0]=Contest[1][0];
	a[1][0][1]=Contest[1][1];
	for(int i=2;i<=n;i++){
		for(int j=0;j<=15&&j<=i;j++)
			for(int k=0;k<=15&&j+k<=i;k++){
				int largest=a[i-1][j][k];
				if((j>0)&&largest<a[i-1][j-1][k]+Contest[i][0])
					largest=a[i-1][j-1][k]+Contest[i][0];
				if((k>0)&&largest<a[i-1][j][k-1]+Contest[i][1])
					largest=a[i-1][j][k-1]+Contest[i][1];
				a[i][j][k]=largest;
			}
	}
}

int main(){
	init();
	solve();
	cout<<a[n][15][15]<<endl;
	return 0;
}