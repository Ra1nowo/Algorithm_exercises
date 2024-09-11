#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
vector<int> g[N];
int vis[N];

bool dfs(int u) {
    vis[u] = 0;
    for (int v:g[u]) {
        if (vis[v] == -1) {
            if (dfs(v)) return true;
        }
        if (vis[v] == 0) return true;
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // 初始化图
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    fill(vis,vis+n,-1);
    bool hasCycle = false;
    for (int i = 0; i < n; ++i) {
        if (vis[i] == -1) {
            if (dfs(i)) {
                hasCycle = true;
                break;
            }
        }
    }
    
    if (hasCycle) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
