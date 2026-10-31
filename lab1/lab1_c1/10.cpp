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
        bool b_w = false;
        if(x1 == 0 && x2 == 9){
            b_w = true;
        }else if(x1 > x2 && !(x1 == 9 && x2 == 0)){
            b_w = true;
        }
        if(b_w){
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
        cout << "Boris" << " ";
    }else{
        cout << "Nursik" << " ";
    }
    cout << count;
    return 0;
}