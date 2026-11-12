#include <bits/stdc++.h>
using namespace std;

unsigned long long get_hash(string s){
    unsigned long long h = 0;
    unsigned long long p = 29;
    unsigned long long p_pow = 1;

    for(int i = 0; i < s.size(); i++){
        h += s[i] * p_pow;
        p_pow *= p;
    }

    return h;
}


int main(){
    string s;
    cin >> s;

    cout << get_hash(s);


    return 0;
}