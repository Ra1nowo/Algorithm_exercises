#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int a,b,w;
    Edge(int _a,int _b,int _w) {
        a = _a,b = _b,w = _w;
    }
};
const int N = 1e5;
int p[N];
vector<Edge> edges;

bool cmp(Edge e1, Edge e2) {
    return e1.w < e2.w; 
}

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        p[rx] = ry;
    }
}

int kruskal(int n, int m) {
    int res= 0;
    int cnt = 0;
    sort(edges.begin(),edges.end(),cmp);
    for (int i = 0; i < m; ++i) {
        if (find(edges[i].a) != find(edges[i].b)) {
            res += edges[i].w;
            cnt++;
            merge(edges[i].a, edges[i].b);
        }
    }
    if (cnt != n-1) return -1;
    return res;
}



int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u,v,w));
    }
    for (int i = 0; i < n; ++i) p[i] = i;
    int res = kruskal(n,m);
    cout << res << endl;
    return 0;
}
