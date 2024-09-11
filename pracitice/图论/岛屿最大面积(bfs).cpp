#include <iostream>
#include <queue>
using namespace std;

const int N = 100;
int g[N][N],n,m,dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

int bfs(int x, int y) {
    int area = 1;
    queue<pair<int,int>> q;
    q.push({x,y});
    g[x][y] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = u.first + dx[i], ny = u.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && g[x][ny] == 1) {
                g[nx][ny] = 0;
                area++;
                q.push({nx,ny});
            }
        }
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
                res = max(res,bfs(i,j));
            }
        }
    }
    cout << res << endl;
    return 0;
}
