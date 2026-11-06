#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int>& a, int target){
    int l = 0;
    int r = a.size();
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] < target){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }

    return l;
}

int upper_bound(vector<int>& a, int target){
    int l = 0;
    int r = a.size();
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] <= target){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    int m;
    cin >> m;
    for(int i = 0;i < m; i++){
        int target;
        cin >> target;
        cout << (upper_bound(a, target) - lower_bound(a, target)) << '\n';
    }
    return 0;
}