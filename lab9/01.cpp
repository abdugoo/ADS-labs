#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1;i < n; i++){
        int j = pi[i - 1];
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
    string text, pattern;
    cin >> text >> pattern;
    int m = pattern.size();
    string s = pattern + "#" + text;
    vector<int> pi = prefix_function(s);
    for(int i = m + 1; i < s.size(); i++){
        if(pi[i] == m){
            cout << i - 2 * m << " ";
        }
    }

    return 0;
}