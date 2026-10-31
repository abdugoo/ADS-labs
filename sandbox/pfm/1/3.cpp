#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    queue<long long> a;
    for(int i = 0;i < n; i++){
        string t;
        cin >> t;
        if(t == "push"){
            long long x;
            cin >> x;
            a.push(x);
        }
        else{
            long long front = a.front();
            a.pop();
            cout << front << '\n';
        }
    }


    return 0;
}