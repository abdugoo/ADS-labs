#include <bits/stdc++.h>
using namespace std;

void binexp(){
    long long a, n, m;
    cin >> a >> n >> m;
    long long result = 1;
    while(n > 0){
        if(n % 2 == 1){
            result = ((result % m) * (a % m)) % m;
        }
        a = ((a % m) * (a % m)) % m;
        n /= 2;
    }

    cout << result % m;
}

int main(){
    binexp();
    return 0;
}