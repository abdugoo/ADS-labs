#include <bits/stdc++.h>
using namespace std;

vector<unsigned long long> get_hash_vector(string s){
    int n = s.size();

    vector<unsigned long long> h(n);

    if(n == 0){
        return h;
    }
    h[0] = s[0];
    unsigned long long p = 29;
    unsigned long long p_pow = 29;

    for(int i = 1;i < n; i++){
        h[i] = h[i - 1] + s[i] * p_pow;
        p_pow *= p;

    }
    return h;
}


int main(){
    string s;
    cin >> s;
    vector<unsigned long long> a = get_hash_vector(s);

    for(auto x: a){
        cout << x << " ";
    }


    return 0;
}