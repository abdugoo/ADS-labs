#include <bits/stdc++.h>
using namespace std;


void quick_sort(int l, int r, vector<int>& a){
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;    

    while(i < j){
        while(a[i] < p){
            i++;
        }
        while(p < a[j]){
            j--;
        }

        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(l < j){
        quick_sort(l, j, a);
    }
    if(i < r){
        quick_sort(i, r, a);
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a.push_back(x);
    }
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        b.push_back(x);
    }
    if(n > 1) quick_sort(0, n - 1, a);
    if(m > 1) quick_sort(0, m - 1, b);
    int c1 = 0;
    int c2 = 0;
    while(c1 != n and c2 != m){
        if(a[c1] == b[c2]){
            cout << a[c1] << ' ';
            c1++;c2++;
        }
        else if(a[c1] > b[c2]){
            c2++;
        }
        else{
            c1++;
        }

    }




    return 0;
}