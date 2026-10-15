#include <bits/stdc++.h>
using namespace std;

int a[1000];

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        bool ok = true;
        for(int j = 0; j < n - i - 1; j++){
            if(a[j] > a[j + 1]){
                ok = false;
                swap(a[j], a[j + 1]);
            }
        }
        if(ok){
            break;
        }

        for(int k = 0; k < n; k++){
            cout << a[k] << " ";
        }
        cout << endl;
    }




    return 0;
}