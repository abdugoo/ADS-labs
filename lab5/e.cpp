#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long q, k;
    cin >> q >> k;
    long long ans = 0;
    priority_queue<long, vector<long>, greater<long>> pq;
    for(int i = 0; i < q; i++){
        string command;
        cin >> command;
        if(command == "print"){
            cout << ans << '\n';
        }
        else{
            long n;
            cin >> n;
            if(pq.size() < k){
                pq.push(n);
                ans += n;
               
            }
            else if(pq.top() < n){
                ans -= pq.top();
                pq.pop();

                ans += n;
                pq.push(n);
            }
        }
    }



    return 0;
}