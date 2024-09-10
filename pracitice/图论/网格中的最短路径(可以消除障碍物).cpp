#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct pos {
    int x, y;
    int rest;
    pos(int _x, int _y, int _r) : x(_x), y(_y), rest(_r) {}
};

int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        int steps = 0;
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));
        queue<pos> q;
        q.emplace(0, 0, k);
        vis[0][0][k] = true;

        while (!q.empty()) {
            int cnt = q.size();
            for (int i = 0; i < cnt; ++i) {
                auto u = q.front();
                q.pop();
                if (u.x == n-1 && u.y == m-1) return steps;
                for (int i = 0; i < 4; ++i) {
                    int nx = u.x + dx[i], ny = u.y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == 0 && !vis[nx][ny][u.rest]) {
                            vis[nx][ny][u.rest] = true;
                            q.emplace(nx, ny, u.rest);
                        }
                        if (grid[nx][ny] == 1 && u.rest > 0 && !vis[nx][ny][u.rest-1]) {
                            vis[nx][ny][u.rest-1] = true;
                            q.emplace(nx, ny, u.rest-1);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
