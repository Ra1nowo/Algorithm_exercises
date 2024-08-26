#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int N = 101;
const int INF = 1e9;
int d[N];
struct Edge {
    int v,w;
    Edge(int _v, int _w) {
        v = _v, w = _w;
    }
};
vector<Edge> g[N];
typedef pair<int,int> pii;    // pii 保存的是节点编号和边权
void dijkstra(int n, int s) {
    priority_queue<pii,vector<pii>,greater<pii>> q;
    fill(d,d+n,INF);
    d[s] = 0;
    q.push(pii(s,0));
    while (!q.empty()) {
        pii x = q.top();
        q.pop();
        int u = x.first;
        int w = x.second;
        if (w > d[u]) continue;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i].v;
            int w = g[u][i].w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                q.push(pii(v,d[v]));
            }
        }
    }   
}

int main() {
    int n,m,s,t;
    cin >> n >> m >> s >> t;
    while (m--) {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back(Edge(v,w));
        g[v].push_back(Edge(u,w));
    }
    dijkstra(n,s);
    int res = d[t] == INF ? -1:d[t];
    cout << res << endl;
    return 0; 
}