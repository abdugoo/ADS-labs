#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<bool> a(8000, true);
    a[0] = false;
    a[1] = false;
    for(int i = 2; i * i < 8000; i++){
        if(a[i]){
            for(int j = i * i; j < 8000; j += i){
                a[j] = false;
            }
        }
    }

    int count = 0;
    for(int i = 0; i < 8000; i++){
        if(a[i]){
            count += 1;
            if(count == n){
                cout << i;
                return 0;
            }
        }
    }


    return 0;
}