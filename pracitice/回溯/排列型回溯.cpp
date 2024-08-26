#include <iostream>
#include <vector>
using namespace std;

vector<int> path;
vector<vector<int>> res;
const int N = 10;
int n;
bool st[N];

void dfs(int dep) {
    if (dep == n) { 
        res.emplace_back(path);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) {
            st[i] = true;
            path.push_back(i);
            dfs(dep+1);
            path.pop_back();
            st[i] = false;
        }
    } 
}

int main() {
    cin >> n;
    dfs(0);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}