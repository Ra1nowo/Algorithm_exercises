#include <iostream>
#include <queue>
using namespace std;
// https://leetcode.cn/problems/shortest-bridge/description/
class Solution {
public:
    int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

    void dfs(int x, int y, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 0 || grid[x][y] == 2) {
            return;
        }
        if (grid[x][y] == 1) {
            grid[x][y] = 2; // Mark this cell as visited
            q.push({x, y}); // Add to queue
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                dfs(nx, ny, grid, q);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        queue<pair<int, int>> q;

        bool found = false;
        for (int i = 0; i < n && !found; ++i) {
            for (int j = 0; j < m && !found; ++j) {
                if (grid[i][j] == 1) {
                    dfs(i, j, grid, q);
                    found = true;
                }
            }
        }

        // Perform BFS to find the shortest path to the second island
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto u = q.front();
                q.pop();
                for (int d = 0; d < 4; ++d) {
                    int nx = u.first + dx[d], ny = u.second + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (grid[nx][ny] == 1) {
                            return ans;
                        }
                        if (grid[nx][ny] == 0) {
                            grid[nx][ny] = 2;
                            q.push({nx, ny});
                        }
                    }
                }
            }
            ++ans;
        }
        return -1; // This return should never be reached if there are always two islands
    }
};
