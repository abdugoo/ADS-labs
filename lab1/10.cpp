#include <iostream>
#include <queue>
using namespace std;


int main(){
    queue<int> a1;
    queue<int> a2;
    for(int j = 0; j < 5; j++){
        int t;
        cin >> t;
        a1.push(t);

    }
    for(int i = 0; i < 5; i++){
        int t;
        cin >> t;
        a2.push(t);
    }
    int count = 0;
    while(!a1.empty() && !a2.empty()){
        int c1 = a1.front();
        a1.pop();
        int c2 = a2.front();
        a2.pop();
        bool b_w = false;
        if(c1 == 0 && c2 == 9){
            b_w = true;
        }else if(c1 > c2 && !(c1 == 9 && c2 == 0)){
            b_w = true;
        }

        if(b_w){
            a1.push(c1);
            a1.push(c2);
        }else{
            a2.push(c1);
            a2.push(c2);
        }



        count++;
    }
    if(!a1.empty()){
        cout << "Boris";
    }else{
        cout << "Nursik";
    }
    cout << " " << count;


    return 0;
}