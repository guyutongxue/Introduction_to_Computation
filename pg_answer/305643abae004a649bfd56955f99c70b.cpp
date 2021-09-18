#include <iostream>

struct Node {
    int no;
    Node* prev;
    Node* next;
};

int main() {
    char comma;
    int n, m, k;
    std::cin >> n >> comma >> m >> comma >> k;
    Node* head{new Node()};
    Node* tail{nullptr};
    Node* prev{nullptr};
    Node* curr{head};
    for (int i = 1; i < n; i++) {
        curr->no = i;
        curr->prev = prev;
        curr->next = new Node();
        prev = curr;
        curr = curr->next;
    }
    curr->no = n;
    curr->prev = prev;
    curr->next = head;
    head->prev = tail = curr;


    curr = head;
    for (int i{1}; i <= k; i++) {
        for (int j{1}; j < m; j++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if (i == k){
            std::cout << curr->no << std::endl;
        }
        
        auto next{curr->next};
        if (head == curr) head = next;
        if (tail == curr) tail = next;
        delete curr;
        curr = next;
    }

    curr = head;
    while (curr != tail) {
        delete curr->prev;
        curr = curr->next;
    }
}