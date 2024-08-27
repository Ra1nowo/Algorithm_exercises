#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 9;
int n;
bool vis[N];
stack<int> stk;
vector<vector<int>> res;
vector<int> path;

bool isValid(vector<int> path) {
    int m = 0;
    for (int i = 0; i < path.size(); ++i) {
        if (path[i] > m) {
            for (int j = m+1; j <= path[i]; ++j) {
                stk.push(j);
            }
            m = path[i];
        }
        if (stk.top() != path[i]) {
            return false;
        }
        else stk.pop();
    }
    return true;
}

void dfs(int idx) {
    if (idx == n && isValid(path)) {
        res.emplace_back(path);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            path.push_back(i);
            dfs(idx+1);
            path.pop_back();
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            if (j < n-1) {
                cout << res[i][j];
                cout << " ";
            }
            else {
                cout << res[i][j];
                cout << endl;
            }
        }
    }
    return 0;
}