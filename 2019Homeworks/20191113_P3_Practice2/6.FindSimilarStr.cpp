#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string pattern;
string list[202];
/**
 * f: DP
 * [the endpos of pattern string][the endpos of dest string]
 * return: the similarity (minimize)
 * 
 * Formula:
 * f[j][k]=
 *     pattern[j]==dest[k]?
 *         f[j-1][k-1]
 *     :
 *         min(f[j][k-1],f[j-1][k])+1  // insert or delete the dest's *pos
 * ;
 * 
*/
int f[502][502];
int main(){
    cin>>pattern;
    int lpattern=pattern.length();
    int n,mmin=1<<20;
    string ans[202];
    int nans=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        string dest;
        cin>>dest;
        int ldest=dest.length();
        for(int j=1;j<lpattern;j++){
            f[j][0]=j;
        }
        for(int j=1;j<ldest;j++){
            f[0][j]=j;
        }
        for(int j=1;j<=lpattern;j++){
            for(int k=1;k<=ldest;k++){
                f[j][k]=(
                    pattern[j]==dest[k]?
                        f[j-1][k-1]
                    :
                        min(f[j][k-1],f[j-1][k])+1
                );
            }
        }
        //cout<<f[lpattern][ldest]<<endl;
        if(f[lpattern][ldest]<mmin){
            mmin=f[lpattern][ldest];
            ans[nans=1]=dest;
        }
        else if(f[lpattern][ldest]==mmin)ans[++nans]=dest;
    }
    for(int i=1;i<=nans;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}