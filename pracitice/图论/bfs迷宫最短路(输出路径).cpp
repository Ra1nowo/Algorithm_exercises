#include <iostream>
#include <queue>
using namespace std;

typedef pair<int,int> pos;
const int N = 101;
bool vis[N][N];
int maze[N][N],step,n,m;
pos pre[N][N];
int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};

void bfs(int x, int y) {
    queue<pos> q;
    q.push(pos(x,y));
    vis[x][y] = true;
    while (!q.empty()) {
        for (int i = 0; i < q.size(); ++i) {
            pos u = q.front();
            q.pop();
            if (u.first == n-1 && u.second == m-1) return;
            for (int i = 0; i < 4; ++i) {
                int nx = u.first + dx[i],ny = u.second + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && !vis[nx][ny]) {
                    pre[nx][ny] = pos(u.first,u.second);
                    vis[nx][ny] = true;
                    q.push(pos(nx,ny));
                } 
            }
            step++;
        }
    }
}

void showPath(pos p) {
    if (p == pos(-1,-1)) return;
    showPath(pre[p.first][p.second]);
    cout << p.first + 1 << " " << p.second + 1 << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    fill(&pre[0][0], &pre[0][0] + N*N, pos(-1, -1));
    bfs(0,0);
    showPath(pos(n-1,m-1));
    return 0;
}