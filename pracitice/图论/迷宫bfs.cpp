#include <iostream>
#include <queue>
// https://sunnywhy.com/problem/320
using namespace std;

const int N = 101;
int g[N][N], m, n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vis[N][N];
typedef pair<int, int> pos;

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && !vis[x][y];
}

int bfs(int startX, int startY) {
    queue<pos> q;
    q.push({startX, startY});
    vis[startX][startY] = true;
    int steps = 0;

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto u = q.front();
            q.pop();
            if (u.first == n-1 && u.second == m-1) return steps;
            for (int j = 0; j < 4; ++j) {
                int nx = u.first + dx[j], ny = u.second + dy[j];
                if (isValid(nx, ny)) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        ++steps;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    
    
    int result = bfs(0, 0);
    cout << result << endl;
    
    return 0;
}
