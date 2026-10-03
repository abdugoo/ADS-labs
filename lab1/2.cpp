#include <iostream>
using namespace std;

long long BinExpMod(long long a,long long n, long long m){
    long long result = 1;
    while(n > 0){
        if(n % 2 == 1){
            result = ((result % m) * (a % m)) % m;
        }
        a = ((a % m) * (a % m)) % m;
        n /= 2;
    }
    return result % m;
}



int main(){
    long long a, n, m;
    cin >> a >> n >> m;

    cout << BinExpMod(a, n, m);

    return 0;
}