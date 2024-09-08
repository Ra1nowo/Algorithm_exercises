#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int N = 1e6 + 10;
vector<int> g[N];
int color[N];

bool bfs(int i) {
    color[i] = 1;
    queue<int> q;
    q.push(i);
    while (!q.empty()) {
        int cnt = q.size();
        for (int i = 0; i < cnt; ++i) {
            int x = q.front();
            q.pop();
            for (int u:g[x]) {
                if (!color[u]) {
                    color[u] = 3 - color[x];
                    q.push(u);
                }
                else if (color[u] == color[x]) return false;
            }
        }
    }
    return true;
}



int main() {
    memset(color,0,sizeof(color));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    string flag = "Yes";
    for (int i = 0; i < n; ++i) {
        if (color[i] == 0) {
            if (!bfs(i)) {
                flag = "No";
                break;
            }
        }
    }
    cout << flag << endl;
    return 0;
} 