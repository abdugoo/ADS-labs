#include <iostream>
#include <vector>
using namespace std;




int main(){
    int n;
    cin >> n;
    vector<bool> prime_numbers(7920, true);
    prime_numbers[0] = false;
    prime_numbers[1] = false;

    for(int i = 2; i * i <= 7920; i++){
        if(prime_numbers[i]){
            for(int j = i * i; j <= 7920; j += i){
                prime_numbers[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 2; i < 7920; i++){
        if(prime_numbers[i]){
            count += 1;
            if(count == n){
                cout << i;
                return 0;
            }
        }
    }



    return 0;
}