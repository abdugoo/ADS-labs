#include <bits/stdc++.h>
using namespace std;

struct Date{
    int day, month, year;
    string original;
};

bool smaller(Date a, Date b){
    if(a.year != b.year){
        return a.year < b.year;
    }
    if(a.month != b.month){
        return a.month < b.month;
    }
    
    return a.day < b.day;
}

void quick_sort(int l, int r, vector<Date>& a){
    Date p = a[(l + r) / 2];
    int i = l;
    int j = r;

    while(i <= j){
        while(smaller(a[i], p)){
            i++;
        }
        while(smaller(p, a[j])){
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
    vector<Date> dates(n);

    for(int i = 0; i < n; i++){
        cin >> dates[i].original;

        dates[i].day = stoi(dates[i].original.substr(0, 2));
        dates[i].month = stoi(dates[i].original.substr(3, 2));
        dates[i].year = stoi(dates[i].original.substr(6, 4));

    }
    quick_sort(0, n-1, dates);

    for(int i = 0;i < n; i++){
        cout << dates[i].original << '\n';
    }


    return 0;
}