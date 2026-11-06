#include <bits/stdc++.h>
using namespace std;

void quick_sort(int l, int r, vector<int>& a){
    int i = l;
    int j = r;
    int p = a[(l + r) / 2];
    while(i <= j){
        while(a[i] < p){
            i++;
        }
        while(a[j] > p){
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    int k;
    cin >> k;
    quick_sort(0, n - 1, a);
    cout << a[k - 1];
    return 0;
}