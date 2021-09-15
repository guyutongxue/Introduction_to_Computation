#include<iostream>
#include<cstring>
using namespace std;
bool a[502][502];
int main(){
    memset(a,false,sizeof(a));
    int n;
    cin>>n;
    while(n--){
        int cmd,x1,y1,x2,y2;
        cin>>cmd>>x1>>y1>>x2>>y2;
        x1++;
        y1++;
        if(cmd){
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    if(!a[i][j]){
                        cout<<"No"<<endl;
                        goto endofwhile;
                    }
                }
            }
            cout<<"Yes"<<endl;
        }
        else{
            for(int i=x1;i<=x2;i++){
                for(int j=y1;j<=y2;j++){
                    a[i][j]=true;
                }
            }
        }
        endofwhile:;
    }
}