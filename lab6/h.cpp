#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<char> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    char target;
    cin >> target;

    for(int i = 0; i < n; i++){
        if(a[i] > target){
            cout << a[i];
            return 0;
        }
    }

    cout << a[0];

    return 0;
}