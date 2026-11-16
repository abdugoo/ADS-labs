#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);

    for (int i = 0; i < q; i++) {
        int type, v;
        cin >> type >> v;

        if (type == 1) {
            if (dist[v] != 0) {
                dist[v] = 0;
                queue<int> bfs_q;
                bfs_q.push(v);

                while (!bfs_q.empty()) {
                    int u = bfs_q.front();
                    bfs_q.pop();

                    for (int nxt : adj[u]) {
                        if (dist[nxt] == -1 || dist[nxt] > dist[u] + 1) {
                            dist[nxt] = dist[u] + 1;
                            bfs_q.push(nxt);
                        }
                    }
                }
            }
        } else {
            cout << dist[v] << "\n";
        }
    }

    return 0;
}