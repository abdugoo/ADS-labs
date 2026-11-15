#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007, p = 31;

int main(){
    int n;
    while(cin >> n && n != 0){
        vector<string> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        string s;
        cin >> s;
        int len = s.size();
        vector<long long> h(len + 1, 0), pw(len + 1, 1);
        for(int i = 1;i <= len; i++){
            int x = s[i - 1] - 'a' + 1;
            h[i] = (h[i - 1] * p + x) % mod;
            pw[i] = (pw[i - 1] * p) % mod;
        }
        vector<int> cnt(n, 0);
        int best = 0;
        for(int j = 0; j < n; j++){
            int m = a[j].size();
            long long target = 0;
            for(char c: a[j]){
                target = (target * p + c - 'a' + 1) % mod;
            }
            for(int i = 0; i + m <= len; i++){
                long long cur = (h[i + m] - h[i] * pw[m] % mod + mod) % mod;
                if(cur == target){
                    cnt[j]++;
                }
            }
            best = max(best, cnt[j]);
        }
        cout << best << '\n';
        for(int i = 0; i < n; i++){
            if(cnt[i] == best){
                cout << a[i] << '\n';
            }
        }
    }


    return 0;
}