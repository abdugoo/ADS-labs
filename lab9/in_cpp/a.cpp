#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string& s) {
    int n = s.size();
    vector<int> h(n);
    h[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = h[i-1];
        while(j > 0 && s[i] != s[j]){
            j = h[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        h[i] = j;
    }
    return h;
}

int main() {
    string a, b;
    cin >> a >> b;
    string rep_a = a;
    int cnt = 1;
    while(rep_a.size() < b.size()) {
        rep_a += a;
        ++cnt;
    }
    for (int k = 0; k < 3; k++) {
        string s = b + "#" + rep_a;
        vector<int> p = prefix_function(s);
        bool found = false;
        for (int i = b.size() + 1; i < s.size(); ++i) {
            if (p[i] == b.size()) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << cnt << endl;
            return 0;
        }
        rep_a += a;
        ++cnt;
    }
    cout << -1 << endl;
    return 0;
}