#include <bits/stdc++.h>
using namespace std;

const long long m1 = 1000000007, m2 = 1000000009, p = 31;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<long long> h1(n + 1, 0), h2(n + 1, 0);
    vector<long long> p1(n + 1, 1), p2(n + 1, 1);
    for(int i = 0;i < n; i++){
        int x = s[i] - 'a' + 1;
        h1[i + 1] = (h1[i] * p + x) % m1;
        h2[i + 1] = (h2[i] * p + x) % m2;
        p1[i + 1] = p1[i] * p % m1;
        p2[i + 1] = p2[i] * p % m2;
    }
    long long ans = 0;
    for(int len = 1; len <= n; len++){
        unordered_set<unsigned long long> seen;
        for(int i = 0;i + len <= n; i++){
            long long a = (h1[i + len] - h1[i] * p1[len] % m1 + m1) % m1;
            long long b = (h2[i + len] - h2[i] * p2[len] % m2 + m2) % m2;
            unsigned long long key = (static_cast<unsigned long long>(a) << 32) | b;
            seen.insert(key);
        }
        ans += seen.size();
    }
    cout << ans;

    return 0;
}