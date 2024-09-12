#include <iostream>
using namespace std;

const int N = 201;
int g[N][N];
int n;
// https://leetcode.cn/problems/number-of-provinces/description/
void dfs(int u) {
    for (auto v:g[u]) {
        if (g[u][v] == 1) {
            g[u][v] = 0;
            dfs(v);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (g[i][i] == 1) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}