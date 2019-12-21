#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

struct Heap{
    int value;
    int sum;
    Heap(){
        value=sum=0;
        left=right=parent=NULL;
    }
    Heap* left;
    Heap* right;
    Heap* parent;
};

int main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Heap* arr=new Heap[n+1];
        for(int i=1;i<=n;i++){
            int v;
            cin>>v;
            (arr+i)->value=v;
        }
        for(int i=1;i<=n-1;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(c){
                (arr+a)->right=(arr+b);
                (arr+b)->parent=(arr+a);
            }
            else{
                (arr+a)->left=(arr+b);
                (arr+b)->parent=(arr+a);
            }
        }
        Heap* root=NULL;
        for(int i=1;i<=n;i++){
            Heap* cur=arr+i;
            while(true){
                cur->sum+=(arr+i)->value;
                if(cur->parent==NULL){
                    root=cur;
                    break;
                }
                cur=cur->parent;
            }
        }
        Heap* p=root;
        while(p->left!=NULL||p->right!=NULL){
            if(p->left==NULL)p=p->right;
            else if(p->right==NULL)p=p->left;
            else if(p->left->sum<p->right->sum)p=p->right;
            else p=p->left;
        }
        for(int i=1;i<=n;i++)if(p==arr+i)cout<<i<<endl;
        delete[] arr;
    }
    return 0;
}