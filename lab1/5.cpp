#include <iostream>
using namespace std;


int main(){
    long long a;
    cin >> a;
    for(long i = 2; i * i <= a; i++){
        while(a % i == 0){
            cout << i << " ";
            a /= i;
        }
    }
    if(a > 1){
        cout << a;
    }
    return 0;
}