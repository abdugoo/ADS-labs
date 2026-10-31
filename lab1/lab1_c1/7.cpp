#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> a;
    for(char x: s){
        if(!a.empty() && a.top() == x){
            a.pop();
        }
        else{
            a.push(x);
        }
    }

    if(a.empty()){
        cout << "YES";
    }
    else{
        cout << "NO";
    }



    return 0;
}