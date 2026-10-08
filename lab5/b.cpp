#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
public:
    vector<long long> a;

    MaxHeap(vector<long long> data){
        a = data;

        for(int i = int(a.size() / 2 - 1); i >= 0; i--){
            heapify(i);
        }
    }
    
    void heapify(int i){
        int n = a.size();

        while(true){
            int left = i * 2 + 1;
            if (left >= n)
                break;
            
            int right = left + 1;
            int biggest = left;

            if (right < n && a[right] >= a[left]){
                biggest = right;
            }

            if (a[i] >= a[biggest]){
                break;
            }
            swap(a[i], a[biggest]);
            i = biggest;
        }
    }

    long long extractMax(){
        long long max = a[0];

        a[0] = a.back();
        a.pop_back();

        if(!a.empty()){
            heapify(0);
        }
        return max;
    }



};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> numbers(n);
    for(int i = 0; i < n; i++){
        cin >> numbers[i];
    }

    MaxHeap heap(numbers);
    
    while(heap.a.size() > 1){
        long long x1 = heap.extractMax();
        long long x2 = heap.a[0];
        if (x1 == x2){
            heap.extractMax();
        }
        else{
            heap.a[0] = abs(x1 - x2);
        }
        heap.heapify(0);
    }

    if(heap.a.size() > 0){
        cout << heap.a[0];
    }
    else{
        cout << 0;
    }


    return 0;
}