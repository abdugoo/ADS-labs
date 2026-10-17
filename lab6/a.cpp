#include <bits/stdc++.h>
using namespace std;

void quick_sort(int l, int r, vector<char>& a){
    int p = a[(l + r) / 2];
    int i = l;
    int j = r;


    while(i <= j){
        while(a[i] < p){
            i++;
        }
        while(a[j] > p){
            j--;
        }

        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j){
        quick_sort(l, j, a);
    }
    if(i < r){
        quick_sort(i, r, a);
    }
}

bool check_vowel(char x){
    if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<char> x1;
    vector<char> x2;
    for(int i = 0;i < n; i++){
        char x;
        cin >> x;
        if(check_vowel(x)){
            x1.push_back(x);
        }
        else{
            x2.push_back(x);
        }
    }
    if(!x1.empty()){
        quick_sort(0, (int)x1.size() - 1, x1);
            for(char x: x1){
                cout << x;
            }
    }
    if(!x2.empty()){
        quick_sort(0, (int)x2.size() - 1, x2);
            for(char x: x2){
                cout << x;
            }
    }





    return 0;
}