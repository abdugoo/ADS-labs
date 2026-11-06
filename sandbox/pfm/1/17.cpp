#include <bits/stdc++.h>
using namespace std;

void sift_down(vector<int>& a, int i, int n){
    while(i * 2 + 1 < n){
        int child = i * 2 + 1;
        if(child + 1 < n && a[child + 1] > a[child]){
            child++;
        }

        if(a[i] >= a[child]){
            break;

        }

        swap(a[i], a[child])
        i = child;
    }
}


int main(){


    return 0;
}