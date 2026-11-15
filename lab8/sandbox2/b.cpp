#include <bits/stdc++.h>
using namespace std;
const long long m1 = 1000000007, m2 = 1000000009, p = 31;

struct hsh{
    vector<long long> h1, h2, p1, p2;
    hsh(string s){
        int n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        for(int i = 0;i < n ; i++){
            int x = s[i] - 'a' + 1;
            h1[i + 1] = (h1[i] * p + x) % m1;
            h2[i + 1] = (h2[i] * p + x) % m2;
            p1[i + 1] = p1[i] * p % m1;
            p2[i + 1] = p2[i] * p % m2;
        }
    }
    
    long long get1(int l, int len) {return (h1[l + len] - h1[l] * p1[len] % m1 + m1) % m1;}
    long long get2(int l, int len) {return (h2[l + len] - h2[l] * p2[len] % m2 + m2) % m2;}

};

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    hsh A(a), B(b), C(c);
    int n = c.size();
    int lim = min((int)a.size(), (int)b.size()) - n + 1;
    int ans = 0;
    for(int i = 0; i < lim; i++){
        if(A.get1(i, n) == C.get1(0, n) &&
            A.get2(i, n) == C.get2(0, n) &&
            B.get1(i, n) == C.get1(0, n) &&
            B.get2(i, n) == C.get2(0, n)
        ){
            ans++;
        }
    }
    cout << ans;

    return 0;
}