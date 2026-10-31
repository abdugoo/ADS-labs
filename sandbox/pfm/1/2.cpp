#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >>a[i];
    }
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = n - 1; i >= 0; i--){
        Node* new_node = new Node(a[i]);
        if(head == nullptr){
            new_node->next = head;
        }
    }


    return 0;
}