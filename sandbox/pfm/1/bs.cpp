#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& a, int target){
    int l = 0;
    int r = a.size() - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(a[mid] < target){
            l = mid + 1;
        }
        else if(a[mid] > target){
            r = mid - 1;
        }
        else{
            return mid;
        }
    }

    return -1;
}

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

int upper_bound(vector<int> &a, int target){
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


    return 0;
}