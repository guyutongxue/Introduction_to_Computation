//Same as P1-4/3
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
inline int sgn(int x){
    if(x>0)return 1;
    else if(x<0)return -1;
    else return 0;
}
/**
 * Get next point.
 * Use N(N()) or N(N(N())) to find next's next and so on.
*/
inline int N(int x){
    if(x==4)return 1;
    return x+1;
}
class Point{
    private:
        int arr[3];
    public:
        Point(int x,int y,int z){
            arr[0]=x;
            arr[1]=y;
            arr[2]=z;
        }
        Point(int x,int y){
            arr[0]=x;
            arr[1]=y;
            arr[2]=0;
        }
        Point(){
            arr[0]=arr[1]=arr[2]=0;
        }
        int& operator[](int i){
            return arr[i];
        }
        Point operator-(Point p2){
            int x[3];
            x[0]=arr[0]-p2[0];
            x[1]=arr[1]-p2[1];
            x[2]=arr[2]-p2[2];
            Point nx(x[0],x[1],x[2]);
            return nx;
        }
        Point operator*(Point b){//cross
            int C[3];
            C[0]=arr[1]*b[2]-arr[2]*b[1];
            C[1]=arr[2]*b[0]-arr[0]*b[2];
            C[2]=arr[0]*b[1]-arr[1]*b[0];
            Point nC(C[0],C[1],C[2]);
            return nC;
        }
} p[5];


int main(){
    string str;
    while(cin>>p[1][0]>>p[1][1]>>p[2][0]>>p[2][1]>>p[3][0]>>p[3][1]>>p[4][0]>>p[4][1]){
        //for(int i=1;i<=4;i++){
        //    cin>>p[i][0]>>p[i][1];
        //}

        for(int i=1;i<=4;i++){
            Point line=(p[i]-p[N(i)]);//Define the base line.
            int s1=sgn((line*(p[i]-p[N(N(i))]))[2]);
            int s2=sgn((line*(p[i]-p[N(N(N(i)))]))[2]);
            if(s1!=s2||s1==0||s2==0){//If the other two line is in one side of the base line
                cout<<"no"<<endl;
                goto end_of_while;
            }
        }
        cout<<"yes"<<endl;
        end_of_while:;
    }
    return 0;
}