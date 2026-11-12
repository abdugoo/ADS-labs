#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main(){
    string s;
    cin >> s;

    int n = s.size();
    const ull P = 29;
    vector<ull> h(n), p(n);
    p[0] = 1;
    for(int i = 1; i < n; i++){
        p[i] = p[i - 1] * P;
    }

    h[0] = s[0];
    for(int i = 1; i < n; i++){
        h[i] = h[i - 1] + s[i] * p[i];
    }

    int l, r;
    cin >> l >> r;
    if(l > 0){
        cout << h[r] - h[l - 1];
    }
    else{
        cout << h[r];
    }


    return 0;
}