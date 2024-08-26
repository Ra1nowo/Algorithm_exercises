#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 101;
vector<int> g[N],res;
int d[N],cnt = 0;

void topoSort(int n) {
    priority_queue<int,vector<int>,greater<int>> q;
    for (int i = 0; i < n; ++i) {
        if (!d[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        res.push_back(u);
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    while (m--) {
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        d[v2]++;        
    }
    topoSort(n);
    for (int i = 0; i < n; ++i) {
        if (i < n-1) {
            cout << res[i];
            cout << " ";
        }
        else {
            cout << res[i];
            cout << endl;
        }
    }
    return 0;
}