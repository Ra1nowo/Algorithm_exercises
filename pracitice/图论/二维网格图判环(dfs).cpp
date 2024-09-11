#include <iostream>
#include <vector>
using namespace std;
// https://leetcode.cn/problems/detect-cycles-in-2d-grid/
class Solution {
public:
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    vector<vector<bool>> vis; // 用于记录访问状态

    bool dfs(vector<vector<char>>& grid, int x, int y, int px, int py) {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || vis[x][y]) return false;
        vis[x][y] = true;
        for (int i = 0; i < 4; ++i) {  
            int nx = x + dx[i], ny = y + dy[i];
            if (nx == px && ny == py) continue;
            if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == grid[x][y]) {
                if (vis[nx][ny] || dfs(grid, nx, ny, x, y)) return true;
            }
        }
        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m, false)); // 初始化 vis
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!vis[i][j]) {
                    if (dfs(grid, i, j, -1, -1)) return true;
                }
            }
        }
        return false;
    }
};
