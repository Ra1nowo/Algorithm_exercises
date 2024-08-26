#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 101;
vector<int> g[N];
int d[N],cnt = 0;

bool topoSort(int n) {
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            q.push(i);
            cnt++;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
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
        g[v1].push_back(v2);
        d[v2]++;
    }
    string res = topoSort(n)? "Yes":"No";
    cout << res << endl;
    return 0;
}