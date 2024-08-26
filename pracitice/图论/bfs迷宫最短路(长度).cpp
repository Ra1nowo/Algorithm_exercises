#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int N = 101;
bool vis[N][N];
int step;
int maze[N][N];
typedef pair<int,int> pos;
int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void bfs(int x, int y) {
    queue<pos> q;
    q.push(pos(x, y));
    vis[x][y] = true; 
    step = 0;
    
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            pos u = q.front();
            q.pop();
            if (u.first == n-1 && u.second == m-1) return;
            
            for (int j = 0; j < 4; ++j) {
                int nx = u.first + dx[j];
                int ny = u.second + dy[j];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    q.push(pos(nx, ny));
                    vis[nx][ny] = true;
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
    bfs(0, 0);
    cout << step << endl;
}
