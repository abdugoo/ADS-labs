#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int>& a, vector<int>& b){
    long long count = 0;
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;

    while(i < n1 and j < n2){
        if(a[i] > b[j]){
            j++;
        }
        else{
            i++;
            count += j;
        }
    }

    while(i < n1){
        i++;
        count += n2;
    }

    return count;
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

    cout << merge(a, b);




    return 0;
}