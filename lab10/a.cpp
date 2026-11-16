#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    vector<vector<int>> dist(m, vector<int>(n, 0));
    queue<pair<int, int>> q;

    int mushrooms = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                mushrooms++;
            }
        }
    }

    if (mushrooms == 0) {
        cout << 0 << "\n";
        return 0;
    }

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    int max_time = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                grid[nx][ny] = 2;
                dist[nx][ny] = dist[x][y] + 1;
                max_time = max(max_time, dist[nx][ny]);
                mushrooms--;
                q.push({nx, ny});
            }
        }
    }

    if (mushrooms > 0) {
        cout << -1 << "\n";
    } else {
        cout << max_time << "\n";
    }

    return 0;
}