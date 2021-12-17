#include <iostream>
using namespace std;

struct node {
    int num;
    node* next;
};

node* create() {
    node *follow = nullptr, *temp, *head;
    int num;
    head = new node;
    temp = head;
    char ch = '\0';
    cin >> num;
    while (true) {
        temp->num = num;
        follow = temp;
        temp->next = new node;
        temp = temp->next;
        ch = getchar();
        if (ch == '\n') break;
        cin >> num;
    }
    follow->next = nullptr;
    delete temp;
    return (head);
}

void sort(node* p) {
    node *follow, *temp, *tail = nullptr;
    int t = 0;
    while (p->next != tail) {
        follow = p;
        temp = follow->next;
        while (follow->next != tail) {
            if (follow->num > temp->num) {
                t = follow->num;
                follow->num = temp->num;
                temp->num = t;
            }
            follow = temp;
            temp = temp->next;
        }
        tail = follow;
    }
}

void output(node* p) {
    node* temp;
    temp = p;
    while (temp != nullptr) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        node* head = create();
        sort(head);
        output(head);
    }
    return 0;
}