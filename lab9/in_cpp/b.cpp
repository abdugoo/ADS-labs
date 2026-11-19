#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string& s) {
    int n = s.size();
    vector<int> p(n);
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = p[j-1];
        }
        if (s[i] == s[j]){
            ++j;
        }
        p[i] = j;
    }
    return p;
}

int main() {
    string s;
    int k;
    cin >> s >> k;
    string txt;
    cin >> txt;
    string combined = s + "#" + txt;
    vector<int> p = prefix_func(combined);
    int c = 0;
    int len_s = s.size();
    for(int i = len_s + 1; i < combined.size(); ++i) {
        if(p[i] == len_s) {
            ++c;
        }
    }
    if (c >= k) {
        cout << "YES" << endl;
    }else {
        cout << "NO" << endl;
    }
    return 0;
}