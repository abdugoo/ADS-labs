#include <bits/stdc++.h>
using namespace std;


void quick_sort(long l, long r, vector<long>& a){
    long p = a[(l + r) / 2];
    long i = l;
    long j = r;

    while(i <= j){
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
    long n;
    cin >> n;
    vector<long> a(n);
    for(int i = 0; i< n; i++){
        cin >> a[i];
    }
    quick_sort(0, n-1, a);
    long mid = LONG_MAX;
    vector<long> ans;
    for(int i = 0; i < (n - 1); i++){
        long t = abs(a[i] - a[i + 1]);
        if(t < mid){
            mid = t;
            if(ans.size() >= 2){
                ans.clear();
            }
            ans.push_back(a[i]);
            ans.push_back(a[i+1]);
        }
        else if(t == mid){
            ans.push_back(a[i]);
            ans.push_back(a[i+1]);
        }
    }
    for(long x: ans){
        cout << x << " ";
    }
    return 0;
}