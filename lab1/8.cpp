#include <iostream>
#include <stack>
using namespace std;

int main(){

    int n;
    cin >> n;
    stack<int> a;
    a.push(-1)

    for(int i = 0;i < n; i++){
        int t;
        cin >> t;
        while(a.top() >= t){
            a.pop();
        }
        cout << a.top() << " ";
        a.push(t);
    }
    return 0;
}