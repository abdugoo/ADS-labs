#include <bits/stdc++.h>
using namespace std;

void gcd(){
    long long a, b;
    cin >> a >> b;
    long long t = 1;
    while(t != 0){
        t = a % b;
        a = b;
        b = t;
    }
    cout << a;
}

int main(){
    gcd();
    return 0;
}