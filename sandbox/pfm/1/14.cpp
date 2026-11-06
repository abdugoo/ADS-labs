#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> a;
    a.push_back(5);
    a.push_back(3);
    a.push_back(7);
    a.push_back(1);
    a.push_back(2);
    sort(a.begin(), a.end());
    for(int x: a){
        cout << x << ' ';
    }

    return 0;
}