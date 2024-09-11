#include <iostream>
using namespace std;

const int N = 100;
int g[N][N],n,m,dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == 0) {
        return 0;
    }
    g[x][y] = 0;
    int area = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        area += dfs(nx,ny);
    }
    return area;
}

int main() {
    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 1) {
                res = max(res,dfs(i,j));
            }
        }
    }
    cout << res << endl;
    return 0;
}
