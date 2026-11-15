#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007LL;

string hashing(const string& s){
    long long h = 0, p = 1;
    for(char c: s){
        h = (h + (c - 47) * p) % mod;
        p = p * 11 % mod;
    }
    return to_string(h);
}


int main(){
    int n;
    cin >> n;
    vector<string> h(2 * n);
    unordered_map<string, int> mp;
    for(int i = 0; i < 2* n; i++){
        cin >> h[i];
        mp[h[i]]++;
    }
    int cnt = 0;
    for(int i = 0;i < 2 * n && cnt < n; i++){
        string hs = hashing(h[i]);
        if(mp.count(hs)){
            cout << "Hash of string \"" << h[i] << "\" is " << hs << '\n';
            cnt++;
        }
    }

    return 0;
}