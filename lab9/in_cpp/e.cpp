×
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Нахождение наибольшего совпадающего префикса и суффикса через КМП
int get_max_border_kmp(const string& s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi[n - 1];
}

void solve() {
    string s;
    long long k;
    if (!(cin >> s >> k)) return;

    long long n = s.length();
    long long border = get_max_border_kmp(s);

    // Минимальная длина по формуле
    long long ans = n + (k - 1) * (n - border);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}