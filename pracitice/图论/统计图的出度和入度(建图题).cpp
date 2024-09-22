#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int indegree[N], outdegree[N];


int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        indegree[v]++;
        outdegree[u]++;
    }
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
        if (indegree[i] == n-1 && outdegree[i] == 0) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}