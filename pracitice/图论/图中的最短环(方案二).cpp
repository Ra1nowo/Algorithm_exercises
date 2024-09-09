#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int N = 501, INF = 1e9;
vector<int> g[N];
int dist[N];


    int bfs(int s, int t) {
        queue<int> q;
        memset(dist,-1,sizeof(dist));
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    if (u == s && v == t) continue; // Skip if the edge is the one we started with
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist[t] == -1 ? INF : dist[t];
    }

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        for (int j:g[i]) {
            ans = min(ans,bfs(i,j)+1);
        }
    }
    int res = (ans == INF) ? -1 : ans;
    cout << res << endl;
    return 0;
}