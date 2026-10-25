#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, vector<int> &b){
    int i = 0;
    int j = 0;
    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            cout << a[i] << " ";
            i++;
        }
        else{
            cout << b[j] << " ";
            j++;
        }
    }

    while(i < a.size()){
        cout << a[i] << " ";
        i++;
    }
    while(j < b.size()){
        cout << b[j] << " ";
        j++;
    }
}



int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    merge(a, b);



    return 0;

}