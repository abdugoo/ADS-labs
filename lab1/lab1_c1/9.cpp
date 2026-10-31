#include <bits/stdc++.h>
using namespace std;

void initially_deck(int n){
    deque<int> q;
    for(int i = n; i > 0; i--){
        q.push_front(i);
        for(int j = 0;j < i;j++){
            q.push_front(q.back());
            q.pop_back();
        }
    }

    for(int x: q){
        cout << x << " ";
    }
    cout << '\n';
}

int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
        int t;
        cin >> t;
        initially_deck(t);
    }

    return 0;
}