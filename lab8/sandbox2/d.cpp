#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    string s = "";
    long long prev = 0, p  = 1;
    for(int i = 0;i < n; i++){
        long long x = (a[i] - prev) / p;
        s += char(x + 'a');
        prev = a[i];
        p *= 2;
    }
    cout << s;
    

    return 0;

}