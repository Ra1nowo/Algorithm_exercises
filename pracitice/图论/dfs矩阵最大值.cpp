#include <iostream>
#include <algorithm>
using namespace std;
// https://sunnywhy.com/problem/315
const int N = 6;
int g[N][N], curr = 0, res = -1e9;
bool vis[N][N];
int m, n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool isValid(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y]);
}

void dfs(int x, int y) {
    if (x == m - 1 && y == n - 1) {
        res = max(res, curr);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx, ny)) {
            vis[nx][ny] = true;
            curr += g[nx][ny];
            dfs(nx, ny);
            vis[nx][ny] = false;
            curr -= g[nx][ny];
        }
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }

    vis[0][0] = true;
    curr = g[0][0]; // 初始化起始位置的权值
    dfs(0, 0);

    cout << res << endl;
    return 0;
}
