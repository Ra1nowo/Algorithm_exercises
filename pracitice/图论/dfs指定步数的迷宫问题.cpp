#include <iostream>
using namespace std;

const int N = 5;
int g[N][N],dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0},n,m,k,step = 0;;
bool vis[N][N];
string res = "No";

void dfs(int x, int y) {
    if (x == n-1 && y == m-1) {
        if (step == k) res = "Yes";
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && x < n && y >= 0 && y < m && g[nx][ny] == 0 && !vis[nx][ny]) {
            step++;
            vis[nx][ny] = true;
            dfs(nx,ny);
            step--;
            vis[nx][ny] = false;
        }
    }
}


int main() {
    cin >> n >> m >> k;
    vis[0][0] = true;
    dfs(0,0);
    cout << res << endl;
    return 0;
}