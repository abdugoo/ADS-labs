#include <bits/stdc++.h>
using namespace std;

void merge(int left, int mid, int right, vector<string> &a){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<string> L(n1), R(n2);
    for(int i = 0;i < n1; i++){
        L[i] = a[left + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = a[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2){
        if(L[i].size() <= R[j].size()){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
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

void merge_sort(int left, int right, vector<string> &a){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(left, mid, a);
        merge_sort(mid + 1, right, a);
        merge(left, mid, right, a);
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; i++){
        string line;
        getline(cin, line);

        stringstream reader(line);

        vector<string> a;
        string t;
        while(reader >> t){
            a.push_back(t);
        }
        merge_sort(0, a.size() - 1, a);
        for(string x: a){
            cout << x << " ";
        }
        cout << '\n';
    }
    return 0;
}