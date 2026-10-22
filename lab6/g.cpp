#include <bits/stdc++.h>
using namespace std;

void quick_sort(int l, int r, vector<pair<string, string>> &a){
    string p = a[(l + r) / 2].first;
    int i = l;
    int j = r;
    while(i <= j){
        while(a[i].first < p){
            i--;
        }
        while(p < a[j].first){
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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    map<string, string> owner;
    map<string, string> current;
    vector<string> originals;
    for(int i = 0; i < n; i++){
        string oldname, newname;
        cin >> oldname >> newname;

        string real_owner;
        if(owner.count(oldname)){
            real_owner = owner[oldname];
        }else{
            real_owner = oldname;
            originals.push_back(real_owner);
        }

        current[real_owner] = newname;
        owner[newname] = real_owner;
        owner[oldname] = real_owner;
    }

    vector<pair<string, string>> ans;
    for(string name: originals){
        if(current.count(name)){
            ans.push_back({name, current[name]});
        }
    }

    quick_sort(0, (int)ans.size() - 1, ans);
    cout << ans.size() << '\n';
    for(auto p: ans){
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}