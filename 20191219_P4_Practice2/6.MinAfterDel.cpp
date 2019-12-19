#include<iostream>
#include<string>
using namespace std;
int main(){
	string c;
	int k,len,d;
	cin>>c>>k;
	while(k--){
		for(int i=1;i<c.length();i++){
			if(c[i]<c[i-1]){
				c.erase(i-1,1);
				goto endOfWhile;
			}
        }
        if(!c.empty())c.erase(c.length()-1,1);
        endOfWhile:;
        //cout<<c<<endl;
	}
    while(!c.empty()&&c[0]=='0')c.erase(0,1);
	if(c.empty())cout<<0<<endl;
	else cout<<c<<endl;
	return 0;
}