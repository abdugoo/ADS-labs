#include <bits/stdc++.h>
using namespace std;

void merge(int left, int mid, int right, vector<vector<int>> &a, int &m){
    int n1 = (mid - left + 1);
    int n2 = (right - mid);
    vector<vector<int>> l(n1), r(n2);
    for(int i = 0; i < n1; i++){
        l[i] = a[left + i];
    }
    for(int j = 0; j < n2; j++){
        r[j] = a[mid + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(l[i].back() > r[j].back()){
            a[k] = l[i];
            i++;
        }
        else if(l[i].back() == r[j].back()){
            if(l[i] < r[j]){
                a[k] = l[i];
                i++;
            }
            else{
                a[k] = r[j];
                j++;
            }
        }
        else{
            a[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        a[k] = l[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(int left, int right, vector<vector<int>> &a, int &m){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(left, mid, a, m);
        merge_sort(mid + 1, right, a, m);
        merge(left, mid, right, a, m);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m + 1));
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            sum += a[i][j];
        }
        a[i][m] = sum;
    }
    merge_sort(0, n -1, a, m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }





    return 0;
}