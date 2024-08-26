#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, int> Position;

const int MAXN = 100;
int n, m, maze[MAXN][MAXN];
bool inQueue[MAXN][MAXN] = {false};

const int MAXD = 4;
int dx[MAXD] = {0, 0, 1, -1};
int dy[MAXD] = {1, -1, 0, 0};

bool canVisit(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !inQueue[x][y];
}

int BFS(Position start, Position target) {
    queue<Position> q;
    q.push(start);
    inQueue[start.first][start.second] = true;
    int step = 0;
    while (!q.empty()) {
        int cnt = q.size();
        while (cnt--) {
            Position front = q.front();
            q.pop();
            if (front == target) {
                return step;
            }
            for (int i = 0; i < MAXD; i++) {
                int nextX = front.first + dx[i];
                int nextY = front.second + dy[i];
                if (canVisit(nextX, nextY)) {
                    inQueue[nextX][nextY] = true;
                    q.push(Position(nextX, nextY));
                }
            }
        }
        step++;
    }
    return -1;
}

int main() {
    Position start, target;
    char c;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            if (c == '.') {
                maze[i][j] = 0;
            } else if (c == '*') {
                maze[i][j] = 1;
            } else if (c == 'S') {
                start = Position(i, j);
            } else if (c == 'T') {
                target = Position(i, j);
            }
        }
    }
    int step = BFS(start, target);
    cout << step << endl;
    return 0;
}
