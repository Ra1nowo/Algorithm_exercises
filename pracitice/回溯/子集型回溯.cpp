#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> path;
vector<vector<int>> res;
const int N = 13;
int n;

void dfs(int start) {
    res.emplace_back(path); 
    for (int i = start; i <= n; ++i) {
        path.push_back(i);
        dfs(i + 1);
        path.pop_back();
    }
}

bool cmp(vector<int> &a,vector<int> &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    cin >> n;
    dfs(1);
    sort(res.begin(),res.end(),cmp);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
            if (j + 1 < res[i].size()) { // 控制输出格式
                cout << " ";
            }
        }
        cout << "\n"; // 每个子集一行
    }
    return 0;
}