#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

ull get_hash(string s){
    ull p = 29;
    ull p_pow = 1;
    ull h = 0;

    for(int i = 0;i < s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= p;
    }
    return h;
}

vector<ull> get_h(string s){
    int n = s.size();
    vector<ull> h(n);

    if(n == 0) return h;
    h[0] = s[0];
    ull p = 29;
    ull p_pow = 29;
    for(int i = 1; i < n; i++){
        h[i] = h[i-1] + s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    if(m > n) return 0;

    vector<ull> p(n);
    p[0] = 1;
    for(int i = 1;i < n; i++){
        p[i] = p[i - 1] * 29;
    }

    ull hash_p = get_hash(t);
    vector<ull> h = get_h(s);

    for(int i = 0; i <= n - m; i++){
        int j = i + m - 1;
        ull hash = h[j];
        if(i > 0) hash -= h[i - 1];

        if(hash == hash_p * p[i]){
            cout << i << " ";
        }
    }



    return 0;
}