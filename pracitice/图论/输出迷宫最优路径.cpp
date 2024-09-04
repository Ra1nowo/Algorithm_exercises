#include <iostream>
#include <vector>
using namespace std;

// https://sunnywhy.com/problem/316/solution/1829139784
const int N = 5;
vector<pair<int,int>> path,res;
int g[N][N],n,m,k,curr = 0,ans = -1e9,dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
bool vis[N][N];

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !vis[x][y];
}

void dfs(int x, int y) {
    if (x == n-1 && y == m-1) {
        if (ans < curr) {
            curr = ans;
            res = path;
        }
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx,ny)) {
            curr += g[nx][ny];
            vis[nx][ny] = true;
            path.push_back({nx,ny});
            dfs(nx,ny);
            curr -= g[nx][ny];
            vis[nx][ny] = false;
            path.pop_back();
        }
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
        }
    }
    curr += g[0][0];
    path.push_back({0,0});
    vis[0][0] = true;
    dfs(0,0);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i].first+1 << " " << res[i].second+1 << endl;
    }
    return 0;
}
