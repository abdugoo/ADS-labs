#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1; i < n; i++){
        int j = pi[i - 1];

        while(j > 0 && s[j] != s[i]){
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
    string s;
    cin >> s;
    vector<int> pi = prefix_function(s);

    for(char c: s){
        cout << c << " ";
    }
    cout << '\n';

    for(int i = 0;i < s.size(); i++){
        cout << i << " ";
    }
    cout << "\n";


    for(int t: pi){
        cout << t << " ";
    }


    return 0;
}