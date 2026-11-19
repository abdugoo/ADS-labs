#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_function(const string& s) {
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
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    // s2 - паттерн, s1 - текст
    string combined = s2 + '#' + s1;
    vector<int> pi = prefix_function(combined);

    int len_pat = s2.length();
    vector<int> indices;

    for (int i = len_pat + 1; i < combined.length(); i++) {
        if (pi[i] == len_pat) {
            // Начальный 1-based индекс вхождения в s1
            int start_idx = i - 2 * len_pat + 1;
            indices.push_back(start_idx);
        }
    }

    cout << indices.size() << "\n";
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << (i + 1 == indices.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}