#include <iostream>
#include <vector>
using namespace std;
// https://www.lanqiao.cn/problems/19766/learning/?page=1&first_category_id=1&name=%E7%89%9B%E9%83%8E
const int N = 2e5 + 10;
vector<int> g[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int u = 1; u <= n; ++u) {
        long long num = 0;
        for (int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            num += g[v].size() - 1;
        }
        cout << num << " ";
    }
    return 0;
}