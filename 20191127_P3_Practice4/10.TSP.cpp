//COPIED!!!!


#include <iostream>

using namespace std;
int n;
int a[17][17];
int x[17];
int bestc;
int cc;
void backtrace ( int t )
{
    if( t >  n)
    {
       if( a[x[n]][x[1]] != 0 && ((cc+a[x[n]][x[1]]) < bestc || bestc == 0))
           bestc = cc+a[x[n]][x[1]];
       return;
    }

   else
    {
       for (int i = t ; i<= n ; i++)
       {
           if(a[x[t-1]][x[i]] != 0 && ((cc+a[x[t-1]][x[i]]) < bestc || bestc == 0))//a[t][i]
           {
               swap(x[t],x[i]);//swap 和 cc 的顺序问题啊你妹！
               cc +=  a[x[t-1]][x[t]] ;
               backtrace(t+1);
               cc -=  a[x[t-1]][x[t]];
               swap(x[i],x[t]);

           }
       }
    }
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n ; i ++)
       for(int j = 1 ; j <= n ; j ++)
           cin >> a[i][j];
    cc = 0;
    bestc = 0;
    for(int i = 1 ; i <= n ; i ++)
       x[i] = i;
   backtrace(2);
    cout << bestc << endl;
    return 0;
}