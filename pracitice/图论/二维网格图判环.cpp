#include <iostream>
using namespace std;

const int N = 50;
char g[N][N];
bool vis[N][N];
int n, m, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

bool dfs(int x, int y, int px, int py) {
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y]) return false;
    vis[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx == px && ny == py) continue; // skip the edge we came from
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[nx][ny] == g[x][y]) {
            if (vis[nx][ny] || dfs(nx, ny, x, y)) return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                if (dfs(i, j, -1, -1)) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) break;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
