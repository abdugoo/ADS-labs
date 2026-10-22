#include <bits/stdc++.h>
using namespace std;

void quick_sort(int l, int r, string &s){
    char p = s[(l + r) / 2];
    int i = l;
    int j = r;

    while(i <= j){
        while(s[i] < p){
            i++;
        }
        while(p < s[j]){
            j--;
        }

        if(i <= j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    if(l < j){
        quick_sort(l, j, s);
    }
    if(i < r){
        quick_sort(i, r, s);
    }
}

int main(){
    string s;
    cin >> s;
    quick_sort(0, s.size() - 1, s);
    cout << s;


    return 0;

}