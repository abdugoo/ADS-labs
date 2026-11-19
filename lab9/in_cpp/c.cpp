#include <bits/stdc++.h>
using namespace std;

vector<int> prefix(string& s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = p[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = p[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

int main() {
    string a, b;
    cin >> a >> b;
    string d_b = b + b;
    string combine = a + '#' + d_b;
    vector<int> p = prefix(combine);
    for (int i = a.size() + 1; i < combine.size(); ++i) {
        if (p[i] == a.size()) {
            int pos = i - 2 * a.size();
            if (pos < a.size()) {
                cout << pos;
                return 0;
            }
        }
    }
    cout << -1;
    return 0;
}