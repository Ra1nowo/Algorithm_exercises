#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
//原题链接: https://sunnywhy.com/problem/324
typedef pair<int,int> pos;
const int INF = 0x3f;
const int N = 100;
int n,m,maze[N][N];
bool vis[N][N];
int minStep[N][N];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x,int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !vis[x][y];
}

void bfs(int x,int y) {
    memset(minStep,-1,sizeof(minStep));
    queue<pos> q;
    q.push(pos(x,y));
    vis[x][y] = true;
    minStep[x][y] = 0;
    int step = 0;
    while (!q.empty()) {
        int k = q.size();
        for (int i = 0; i < k; ++i) {
            pos u = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = u.first + dx[i],ny = u.second + dy[i];
                if (isValid(nx,ny)) {
                    vis[nx][ny] = true;
                    minStep[nx][ny] = step + 1;
                    q.push(pos(nx,ny));
                }
            }
        }
        step++;
    }
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> maze[i][j];
        }
    }
    bfs(0,0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j < m-1) {
                cout << minStep[i][j];
                cout << " ";
            }
            else {
                cout << minStep[i][j];
                cout << endl;
            }
        }
    }
    return 0;
} 