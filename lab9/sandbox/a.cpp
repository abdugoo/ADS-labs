#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string& s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i-1];
        while(j > 0 && s[i] != s[j]){
            j = pi[j - 1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main(){
    string a, b;
    cin >> a >> b;
    string rep_a = a;
    int cnt = 1;
    while(rep_a.size() < b.size()){
        rep_a += a;
        cnt++;
    }
    for(int i = 0; i < 2; i++){
        string s = b + "#" + rep_a;
        vector<int> pi = prefix_function(s);
        bool found = false;
        for(int i = b.size() + 1; i < s.size(); i++){
            if(pi[i] == b.size()){
                found = true;
                break;
            }
        }
        if(found){
            cout << cnt;
            return 0;
        }
        rep_a += a;
        cnt++;
    }

    cout << -1;


    return 0;
}