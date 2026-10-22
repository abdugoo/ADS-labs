#include <bits/stdc++.h>
using namespace std;

void quick_sort(int l, int r, vector<long>& a){
    long p = a[(l + r) / 2];
    int i = l;
    int j = r;

    while(i <= j){
        while(a[i] > p){
            i++;
        }
        while(p > a[j]){
            j--;
        }

        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j){
        quick_sort(l, j, a);
    }
    if (i < r){
        quick_sort(i, r, a);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<long>> a(n, vector<long>(m));
    for(int i =0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    for(int j = 0; j < m; j++){
        vector<long> column;
        for(int i = 0; i < n; i++){
            column.push_back(a[i][j]);
        }

        quick_sort(0, n - 1, column);

        for(int i = 0; i < n; i++){
            a[i][j] = column[i];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}