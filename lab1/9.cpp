#include <iostream>
#include <deque>
using namespace std;


void initially_deck(int n){
    deque<int> q;
    for(int i = n; i >= 1; i--){
        q.push_front(i);
        for(int j = 0; j < i; j++){
            int t0 = q.back();
            q.pop_back();
            q.push_front(t0);
        }
    }
    for(int x: q){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        initially_deck(n);
    }




    return 0;
}