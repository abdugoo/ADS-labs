#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(string& s){
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for(int i = 1;i < n; i++){
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
    string a, b;
    cin >> a >> b;
    string s = b + "#" + a;
    vector<int> pi = prefix_function(s);
    vector<int> indices;
    int lenp = b.size();
    for(int i = lenp + 1; i < s.size(); i++){
        if(pi[i] == lenp){
            indices.push_back(i - 2 * lenp + 1);
        }
    }
    cout << indices.size() << "\n";
    for(int i: indices){
        cout << i <<" ";
    }

    return 0;
}