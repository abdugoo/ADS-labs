#include <bits/stdc++.h>
using namespace std;

long long merge(int left, int mid, int right, vector<long long> &a){
    int n1 = (mid - left + 1);
    int n2 = (right - mid);
    long long ans = 0;
    vector<long long> L(n1), R(n2);
    for(int i = 0; i < n1; i++){
        L[i] = a[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
            ans += (n1 - i);
        }
        k++;
    }
    while(i < n1){
        a[k] = L[i];
        i++;k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;k++;
    }
    return ans;
}

long long merge_sort(int left, int right, vector<long long> &a){
    long long ans1 = 0, ans2 = 0, ans3 = 0;
    if(left < right){
        int mid = left + (right - left) / 2;
        ans1 = merge_sort(left, mid, a);
        ans2 = merge_sort(mid + 1, right, a);
        ans3 = merge(left, mid, right, a);
    }
    return ans1 + ans2 + ans3;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }
    cout << merge_sort(0, n - 1, a);






    return 0;
}