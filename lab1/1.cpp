#include <iostream>
using namespace std;


int main(){
    long a, b;
    cin >> a >> b;
    long t;
    while(t != 0){
        t = a % b;
        a = b;
        b = t;
    }
    cout << a;
    return 0;
}