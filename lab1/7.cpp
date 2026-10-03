#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){

    string a;
    cin >> a;
    stack<char> q;
    for(char x: a){
        if(!q.empty() && q.top() == x){
            q.pop();
        }else{
            q.push(x);
        }
    }

    



    if(q.empty()){
        cout << "YES";
    }else{
        cout << "NO";
    }




    return 0;
}