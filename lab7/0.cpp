#include <bits/stdc++.h>
using namespace std;

void merge(int left, int right, int mid, vector<int> &a){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0;i < n1; i++){
        L[i] = a[left + i];
    }
    for(int i = 0;i < n2; i++){
        R[i] = a[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = R[j];
        j++;
        k++;
    }

}

void merge_sort(int left, int right, vector<int> &a){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(left, mid, a);
        merge_sort(mid + 1, right, a);
        merge(left, right, mid, a);
    }
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    merge_sort(0, n - 1, a);
    for(int x: a){
        cout << x << " ";
    }

    return 0;
}