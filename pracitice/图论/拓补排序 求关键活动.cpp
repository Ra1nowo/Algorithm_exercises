#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100;
struct Edge {
    int v, w;
    Edge(int _v, int _w) {
        v = _v, w = _w;
    }
};

vector<Edge> G[N];
int inDegree[N];
vector<int> activity[N];
vector<int> topoOrder;
int ve[N], vl[N];

bool topoSort(int n) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        topoOrder.push_back(u);
        for (auto node : G[u]) {
            int v = node.v, w = node.w;
            if (ve[v] < ve[u] + w) ve[v] = ve[u] + w;
            inDegree[v]--;
            if (inDegree[v] == 0) q.push(v);
        }
    }
    return (int)topoOrder.size() == n;
}

int getCriticalPath(int n) {
    memset(ve, 0, sizeof(ve));
    if (!topoSort(n)) return -1;
    int maxLength = -1;
    for (int i = 0; i < n; ++i) {
        maxLength = max(maxLength, ve[i]);
    }
    fill(vl, vl + n, maxLength);
    for (int i = topoOrder.size() - 1; i >= 0; --i) {
        int u = topoOrder[i];
        for (auto node : G[u]) {
            int v = node.v, w = node.w;
            if (vl[u] > vl[v] - w) vl[u] = vl[v] - w;
        }
    }
    for (int u = 0; u < n; ++u) {
        for (auto node : G[u]) {
            int v = node.v, w = node.w;
            int e = ve[u], l = vl[v] - w;
            if (e == l) activity[u].push_back(v);
        }
    }
    return maxLength;
}


int main() {
    int n, m;
    cin >> n >> m;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        G[u].push_back(Edge(v, w));
        inDegree[v]++;
    }
    int maxLength = getCriticalPath(n);
    if (maxLength == -1) cout << "No" << endl;
    else cout << "Yes" << endl;
    for (int i = 0; i < n; ++i) {
        sort(activity[i].begin(), activity[i].end());
        for (int j = 0; j < activity[i].size(); ++j) {
            cout << i << " " << activity[i][j] << endl;
        }
    }
    return 0;
}