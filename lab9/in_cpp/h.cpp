#include<bits/stdc++.h>

using namespace std;

vector<int> prefix_func(string& s) {
    int n = s.size();
    vector<int> p(n, 0);
    for (int i = 1 ;i < n; ++i) {
        int j = p[i-1];
        while( j > 0 && s[i] != s[j]) {
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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> p = prefix_func(s);
    int cnt = 0;
    for (int i = 1; i * 2 < n; ++i) {
        int len = 2 * i;
        int period = len - p[len - 1];
        if (i % period == 0) {
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}