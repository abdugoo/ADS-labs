#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Node* head = nullptr;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    for(int i = n-1;i >= 0; i--){
        Node* new_node = new Node(a[i]);
        new_node->next = head;
        head = new_node;
    }

    Node* current = head;

    while(current != nullptr and current->next != nullptr){
        current->next = current->next->next;
        current = current->next;
    }
    current = head;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }


    return 0;
}