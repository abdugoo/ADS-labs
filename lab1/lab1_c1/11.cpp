#include <bits/stdc++.h>
using namespace std;

int main(){
    queue<int> a;
    queue<int> b;
    for(int i = 0; i < 5; i++){
        int t;
        cin >> t;
        a.push(t);
    }
    for(int j = 0; j < 5; j++){
        int t;
        cin >> t;
        b.push(t);
    }
    int count = 0;
    while(!a.empty() && !b.empty()){
        int x1 = a.front();
        a.pop();
        int x2 = b.front();
        b.pop();
        bool borsik_wins = false;

        if(x1 == 0 && x2 == 9){
            borsik_wins = true;
        }else if(x1 > x2 && !(x1 == 9 && x2 == 0)){
            borsik_wins = true;
        }

        if(borsik_wins){
            a.push(x1);
            a.push(x2);
        }
        else{
            b.push(x1);
            b.push(x2);
        }
        count++;
    }

    if(!a.empty()){
        cout << "Borsik" << " ";
    }
    else{
        cout << "Nursik" << " ";
    }
    cout << count;

    return 0;
}