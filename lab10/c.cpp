#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    if (a == b) {
        cout << 0 << "\n";
        return 0;
    }

    int max_val = 20005;
    vector<int> dist(max_val, -1);
    vector<int> parent(max_val, -1);
    queue<int> q;

    dist[a] = 0;
    q.push(a);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == b) {
            break;
        }

        if (u * 2 < max_val && dist[u * 2] == -1) {
            dist[u * 2] = dist[u] + 1;
            parent[u * 2] = u;
            q.push(u * 2);
        }

        if (u - 1 >= 1 && dist[u - 1] == -1) {
            dist[u - 1] = dist[u] + 1;
            parent[u - 1] = u;
            q.push(u - 1);
        }
    }

    cout << dist[b] << "\n";

    vector<int> path;
    int curr = b;
    while (curr != a) {
        path.push_back(curr);
        curr = parent[curr];
    }
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i] << (i + 1 == path.size() ? "" : " ");
    }
    cout << "\n";

    return 0;
}