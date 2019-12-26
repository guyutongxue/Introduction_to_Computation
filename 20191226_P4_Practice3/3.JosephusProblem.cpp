#include<iostream>
using namespace std;
struct Node{
    int no;
    Node* next;
    Node* prev;
};
int main(){
    int n,m;
    while(cin>>n>>m,m!=0){
        //Build
        Node* list=new Node[n];
        for(int i=1;i<n-1;i++){
            list[i].no=i+1;
            list[i].next=list+i+1;
            list[i].prev=list+i-1;
        }
        list[0].no=1;
        list[0].next=list+1;
        list[0].prev=list+n-1;
        list[n-1].no=n;
        list[n-1].next=list;
        list[n-1].prev=list+n-2;

        Node* head=list;
        int i=0;
        while(i++,head->next!=head){
            //cout<<i<<" "<<head->no<<endl;
            if(i%m==0){
                //cout<<"Del"<<head->next->no<<endl;
                head->prev->next=head->next;
                head->next->prev=head->prev;
            }
            head=head->next;
        }
        cout<<head->no<<endl;

        //Dispose
        delete[] list;
    }
}