#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 原题链接:https://sunnywhy.com/problem/403
const int N = 101;
int cnt,d[N];
vector<int> g[N],res;

bool topoSort(int n) {
    priority_queue<int ,vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            q.push(i);
            cnt++;
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
                cnt++;
            }
        }
    }
    return cnt == n;
}



int main() {
    int n,m;
    cin >> n >> m;
    while (m--) {
        int v1,v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);  // 邻接表储存
        d[v2]++;
    }
    if (topoSort(n)) {
        cout << "Yes" << endl;
        for (int i = 0; i < res.size(); ++i) {
            if (i < n-1) {
                cout << res[i];
                cout << " ";
            }
            else {
                cout << res[i];
                cout << endl;
            }
        }
    }
    else {
        cout << "No" << endl;
        cout << n - cnt << endl;
    }
    return 0;
}