#include <bits/stdc++.h>
using namespace std;

void merge(int left, int mid, int right, vector<long long> &a){
    int n1 = (mid - left + 1);
    int n2 = right - mid;
    vector<long long> l(n1), r(n2);
    for(int i = 0; i < n1; i++){
        l[n1 - 1 - i] = a[left + i] * a[left + i];
    }
    for(int j = 0;j < n2; j++){
        r[j] = a[mid + 1 + j] * a[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(l[i] < r[j]){
            a[k] = l[i];
            i++;
        }
        else{
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        a[k] = l[i];
        i++;k++;
    }
    while(j < n2){
        a[k] = r[j];
        j++;k++;
    }
}


// 2 5 1 4
// 0 1 2 3
// n = 4

int main(){
    int n;
    cin >> n;
    vector<long long> a(n);
    bool t = true;
    int mid = n - 1;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(t && a[i] >= 0){
            mid = i - 1;
            t = false;
        }
    }
    merge(0, mid, n - 1, a);
    for(long long x: a){
        cout << x << " ";
    }
    return 0;
}