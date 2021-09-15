#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(){data=0,next=NULL;}
};

void dispose(Node* node){
    if(node==NULL)return;
    dispose(node->next);
    delete node;
}

int main(){
    int n;
    cin>>n;

    //Build Linked List
    Node* root=new Node;
    Node* head=root;
    for(int i=1;i<=n;i++){
        int in;
        cin>>in;
        Node* ne=new Node;
        head->next=ne;
        ne->data=in;
        head=head->next;
    }

    //Delete element
    head=root;
    int del;
    cin>>del;
    while(head->next!=NULL){
        while(head->next->data==del){
            Node* expire=head->next;
            head->next=expire->next;
            delete expire;
            if(head->next==NULL)goto outside;
        }
        head=head->next;
    }
    outside:;

    //Output
    head=root;
    while(head->next!=NULL){
        cout<<head->next->data;
        head=head->next;
        cout<<" \n"[head->next==NULL];
    }

    //Dispose
    dispose(root);
    return 0;
}