#include <bits/stdc++.h>
using namespace std;

string cheking(string s){
    string a;
    for(char x: s){
        if(x != '#'){
            a.push_back(x);
        }else{
            if(!a.empty()){
                a.pop_back();
            }
        }
    }
    return a;
}

int main(){
    string a, b;
    cin >> a >> b;
    string x1 = cheking(a);
    string x2 = cheking(b);
    cout << ((x1 == x2)? "Yes" : "No");



    return 0;
}