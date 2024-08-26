#include <iostream>
using namespace std;

const int N = 101;
const int INF = 1e9;
int g[N][N],d[N];
bool vis[N];

void dijkstra(int n, int s) {
    d[s] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && (t == -1 || d[j] < d[t])) {
                t = j;
            }
        }
        if (t == -1) return;
        vis[t] = true;
        for (int v = 0; v < n; ++v) {
            if (d[v] > d[t] + g[t][v]) d[v] = d[t] + g[t][v];
        }
    }
}

int main() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    // 初始化
    fill(vis,vis+n,false);
    fill(d,d+n,INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) g[i][j] = INF;
            else g[i][j] = 0;
        }
    }

    // 构建邻接矩阵
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w; 
    }
    // dijkstra算法
    dijkstra(n,s);

    // 输出结果
    int res = d[t] == INF ? -1:d[t];
    cout << res << endl;
    return 0;
}