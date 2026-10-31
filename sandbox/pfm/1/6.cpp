#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0;i < n; i++){
        int t;
        cin >> t;
        if(a.empty() || a.back() != t){
            a.push_back(t);
        }
    }
    int m;
    cin >> m;
    vector<int> b;
    for(int i = 0;i < m; i++){
        int t;
        cin >> t;
        if(b.empty() || b.back() != t){
            b.push_back(t);
        }
    }

    int i = 0;
    int j = 0;
    n = a.size();
    m = b.size();
    while(i < n && j < m){
        if(a[i] < b[j]){
            cout << a[i] << " ";
            i++;
        }
        else if(a[i] > b[j]){
            cout << b[j] << " ";
            j++;
        }
        else{
            cout << a[i] << " ";
            i++;
            j++;
        }
    }

    while(i < n){
        cout << a[i] << " ";
        i++;
    }
    while(j < m){
        cout << b[j] << " ";
        j++;
    }


    return 0;
}