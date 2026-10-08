#include <bits/stdc++.h>
using namespace std;


int main(){
    long long n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for(int i = 0; i < n; i++){
        long long t;
        cin >> t;
        pq.push(t);
    }
    long count = 0;
    while (pq.size() >= 2 && pq.top() < m){
        long long x1 = pq.top();
        pq.pop();
        long long x2 = pq.top();
        pq.pop();
        long long x = x1 + 2 * x2;
        count += 1;
        pq.push(x);
    }

    if (pq.top() >= m){
        cout << count;
    }
    else{
        cout << -1;
    }





    return 0;
}