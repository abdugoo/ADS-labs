#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;


    priority_queue<int> pq;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        pq.push(t);
    }
    long sum = 0;
    for(int i = 0; i < k; i++){
        int x = pq.top();
        sum += x;
        pq.pop();
        pq.push(x - 1);
    }
    cout << sum;

    return 0;
}