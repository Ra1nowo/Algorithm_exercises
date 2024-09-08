#include <iostream>
#include <cstring>
using namespace std;

const int N = 501,INF = 1e9;
int g[N][N];
int dist[N];
bool vis[N];

int prim(int n) {
    memset(vis,false,sizeof(vis));
    fill(dist,dist+n,INF);
    dist[0] = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1, min_d = INF;
        for (int j = 0; j < n; ++j) {
            if (!vis[j] && dist[j] < min_d) {
                t = j;
                min_d = dist[j];
            }
        }
        if (t == -1) return -1;
        vis[t] = true;
        res += dist[t];
        for (int k = 0; k < n; ++k) {
            dist[k] = min(dist[k],g[t][k]);
        }
    }
    return res;
}


int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        fill(g[i], g[i] + n, INF);
    }    
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        g[x][y] = w;
        g[y][x] = w;
    }
    int res = prim(n);
    cout << res << endl;
    return 0;
}