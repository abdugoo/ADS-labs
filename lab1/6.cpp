#include <iostream>
#include <string>
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
    string a1 = cheking(a);
    string b1 = cheking(b);
    cout << ((a1 == b1)? "Yes": "No");




    return 0;
}