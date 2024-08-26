#include <iostream>
#include <vector>
using namespace std;
// 原题链接:https://www.lanqiao.cn/problems/19686/learning/?page=1&first_category_id=1
const int N = 30;
int a[N],n,m;
vector<int> path;
vector<vector<int>> res;

void dfs(int startIndex) {
    if (path.size() == m) {
        res.emplace_back(path);
        return;
    }
    for (int i = startIndex; i <= n; ++i) {
        path.push_back(i);
        dfs(i+1);
        path.pop_back();
    }
}

int main() {
    cin >> n >> m;
    dfs(1);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    } 
    return 0;
}