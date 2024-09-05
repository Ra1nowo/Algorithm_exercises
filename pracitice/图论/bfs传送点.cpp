#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// https://sunnywhy.com/problem/325/solution/1433167362

typedef pair<int,int> pos;
const int N = 101;
int g[N][N],dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0},n,m;
vector<pos> trans;
bool vis[N][N];

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && (g[x][y] == 0 || g[x][y] == 2) && !vis[x][y]);
}


int bfs(int x, int y) {
    int step = 0;
    queue<pos> q;
    q.push({x,y});
    vis[x][y] = true;
    while (!q.empty()) {
        int siz = q.size();
        for (int i = 0; i < siz; ++i) {
            auto u = q.front();
            q.pop();
            if (u.first == n-1 && u.second == m-1) return step;
            for (int i = 0; i < 4; ++i) {
                int nx = u.first + dx[i], ny = u.second + dy[i];
                if (isValid(nx,ny)) {
                    vis[nx][ny] = true;
                    q.push({nx,ny});
                }
                if (g[nx][ny] == 2) {
                    for (int i = 0; i < trans.size(); ++i) {
                        q.push({trans[i].first,trans[i].second});
                        vis[trans[i].first][trans[i].second] = true;
                    }
                } 
            }
        }
        step++;
    }
    return -1;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == 2) {
                trans.push_back({i,j});
            }
        }
    }
    int step = bfs(0,0);
    cout << step << endl;
    return 0;
}