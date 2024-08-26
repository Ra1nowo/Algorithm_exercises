#include <iostream>
#include <queue>
#include <utility>
using namespace std;
// 原题链接:https://sunnywhy.com/problem/322
const int N = 101;
bool vis[N][N];
int maze[N][N],n,m;
int dx[8] = {0,0,1,2,0,0,-1,-2},dy[8] = {1,2,0,0,-1,-2,0,0};
typedef pair<int,int> pos;

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !vis[x][y]);
}

int bfs(int x, int y) {
    queue<pos> q;
    int steps = 0;
    q.push(pos(x,y));
    vis[x][y] = true;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            pos u = q.front();
            q.pop();
            if (u.first == n-1 && u.second == m-1) return steps;
            for (int j = 0; j < 8; ++j) {
                int nx = u.first + dx[j];
                int ny = u.second + dy[j];
                int nenx = u.first + dx[j] / 2;
                int neny = u.second + dy[j] / 2;
                if (isValid(nx,ny) && maze[nenx][neny] == 0) {
                    vis[nx][ny] = vis[nenx][neny] = true;
                    q.push(pos(nx,ny));
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    int res = bfs(0,0);
    cout << res << endl;
    return 0;
}
