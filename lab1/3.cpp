#include <iostream>
using namespace std;

bool IsPrime(long a){
    if(a == 1){
        return false;
    }
    for(int i = 2;i * i <= a; i++){
        if(a % i == 0){
            return false;
        }
    }
    return true;

}

int main(){
    long a;
    cin >> a;
    if(IsPrime(a)){
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
}