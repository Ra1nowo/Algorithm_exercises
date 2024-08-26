#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//原题链接:https://www.lanqiao.cn/problems/108/learning/?page=1&first_category_id=1

const int N = 1e5 + 10;
int n, d[N];
vector<int> g[N];
vector<int> res;
bool vis[N];

void topoSort(int n) {
    queue<int> q; // 改成priority_queue<int> q也是可以的 下面q.front 改成 q.top()
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 1) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            d[v]--;
            if (d[v] == 1) {
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;    // 树是无向图，需要加双向边
        g[u].push_back(v);
        g[v].push_back(u);
        d[v]++;
        d[u]++;
    }
    topoSort(n);
    
    for (int i = 1; i <= n; ++i) {
        if (d[i] > 1) cout << i << " ";
    }
    return 0;
}
