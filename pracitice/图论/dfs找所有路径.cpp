#include <iostream>
using namespace std;

const int N = 6;
int g[N][N],cnt = 0;
bool vis[N][N];
int m,n;
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

bool isValid(int x, int y) {
    return (x >= 0 && x < m && y < n && y >= 0 && !vis[x][y] && g[x][y] == 0);
}


void dfs(int x, int y) {
    if (x == m-1 && y == n-1) {
        cnt++;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (isValid(nx,ny)) {
            vis[nx][ny] = true;
            dfs(nx,ny);
            vis[nx][ny] = false;
        }
    }
    //vis[x][y] = false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    vis[0][0] = true;
    dfs(0,0);
    cout << cnt << endl;
    return 0;
    
}