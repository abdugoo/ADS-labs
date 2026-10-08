#include <bits/stdc++.h>
using namespace std;

class MinHeap{
public:
    vector<long long> a;

    MinHeap(vector<long long> data){
        a = data;

        for(int i = (int)a.size() / 2 - 1; i >= 0; i--){
            heapify(i);
        }
    }

    void heapify(int i){
        int n = a.size();

        while (true){
            int left = 2 * i + 1;
            
            if(left >= n)
                break;

            int right = left + 1;
            int smallest = left;

            if (right < n && a[right] < a[left]){
                smallest = right;
            }

            if (a[i] <= a[smallest]){
                break;
            }

            swap(a[i], a[smallest]);
            i = smallest;
        }
    }

    long long extractMin(){
        long long mini = a[0];

        a[0] = a.back();
        a.pop_back();

        if (!a.empty()){
            heapify(0);
        }
        return mini;
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

    MinHeap heap(numbers);

    long long ans = 0;
    while (heap.a.size() > 1){
        long long x1 = heap.extractMin();
        long long x2 = heap.a[0];

        long long s = x1 + x2;
        ans += s;

        heap.a[0] = s;
        heap.heapify(0);

    }

    cout << ans << '\n';
    return 0;
}