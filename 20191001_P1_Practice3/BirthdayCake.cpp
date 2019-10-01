#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;
    while(N--){
        int r,x[4],y[4];
        double angle[5];
        cin>>r;
        for(int i=1;i<=3;i++){
            cin>>x[i]>>y[i];
            double d=sqrt(x[i]*x[i]+y[i]*y[i]);
            if(d>r||d==0){
                cout<<"No"<<endl;
                goto end_of_while;
            }
            angle[i]=(y[i]>=0?1:-1)*acos(1.*x[i]/d);
        }
        sort(angle+1,angle+4);
        //for(int i=1;i<=3;i++){
        //    cout<<angle[i]<<endl;
        //}
        if(angle[2]-angle[1]>=(4*M_PI/3)||
        angle[3]-angle[2]>=(4*M_PI/3)||
        angle[1]+2*M_PI-angle[3]>=(4*M_PI/3)   
        ){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
        end_of_while:;
    }
    return 0;
}