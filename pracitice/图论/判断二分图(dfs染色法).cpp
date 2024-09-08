#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;
vector<int> g[N];
int color[N];

bool dfs(int i, int c) {
    color[i] = c;
    for (auto x:g[i]) {
        if (color[x] == 0) {
            if (!dfs(x,3-c)) {
                return false;
            }
        }
        else if (c == color[x]) return false;
    }
    return true;
}


int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    memset(color,0,sizeof(color));
    string flag = "Yes";
    for (int i = 0; i < n; ++i) {
        if (!color[i]) {
            if (!dfs(i,1)) {
                flag = "No";
                break;
            }
        }
    }
    cout << flag << endl;
    return 0;
}

