#include <iostream>
#include <vector>
using namespace std;

const int N = 20;
vector<int> path;
//vector<vector<int>> res;
int a[N],n,k,cnt = 0;
bool vis[N];

void dfs(int dep) {
    bool valid = true;
    if (dep == n) {
        for (int i = 0; i < path.size()-1; ++i) {
            if (abs(path[i] - path[i+1]) >= k) valid = false;  
        }
        if (valid) cnt++;
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            path.push_back(a[i]);
            dfs(dep+1);
            vis[i] = false;
            path.pop_back();
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dfs(0);
    cout << cnt << endl;
    return 0;
}