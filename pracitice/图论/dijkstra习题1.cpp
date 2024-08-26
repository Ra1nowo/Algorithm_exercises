#include <iostream>
#include <queue>
#include <vector>
#include <limits>
using namespace std;
// 原题链接:https://www.lanqiao.cn/problems/1122/learning/?page=1&first_category_id=1&second_category_id=8
typedef long long ll;
const int N = 2e6 + 10;;
const ll INF = 1e18;

vector<pair<int, ll>> g[N];
ll d[N];
bool vis[N];

void dijkstra(int n, int start) {
    fill(d, d + n + 1, INF);
    fill(vis, vis + n + 1, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    
    d[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        ll dist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (vis[u]) continue;
        vis[u] = true;
        
        for (auto &edge : g[u]) {
            int v = edge.first;
            ll weight = edge.second;
            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                pq.push({d[v], v});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
    }

    dijkstra(n, 1);

    for (int i = 1; i <= n; ++i) {
        if (d[i] == INF) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    cout << endl;

    return 0;
}