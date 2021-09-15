#include<iostream>
using namespace std;
int main(){
    # ifdef GENERATION
    for(int i=0;i<=6;i++){
        for(int j=0;j<=6;j++){
            for(int k=1;k<=6;k++){
                if((49*i+7*j+k)==(81*k+9*j+i))
                    cout<<i<<" "<<j<<" "<<k<<endl;
            }
        }
    }
    #endif
    int s;
    cin>>s;
    if(s==1)cout<<248<<endl;
    if(s==2)cout<<503<<endl;
    if(s==3)cout<<305<<endl;
    return 0;
}