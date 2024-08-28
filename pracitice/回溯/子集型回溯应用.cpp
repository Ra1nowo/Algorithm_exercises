// https://sunnywhy.com/problem/139
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N = 13;
int a[N],n,path = 0;
vector<int> res;

void dfs(int idx) {
    res.push_back(path);
    for (int i = idx; i <= n; ++i) {
        path += a[i];
        dfs(i+1);
        path -= a[i];
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1);
    unordered_set<int> set;
    sort(res.begin(),res.end());
    for (int i = 0; i < res.size(); ++i) set.insert(res[i]);
    int len = set.size();
    set.clear();
    for (int i = 0; i < res.size(); ++i) {
        if (set.find(res[i]) != set.end()) continue;
        else {
            if (i < res.size()-1) {
                cout << res[i];
                cout << " ";
            }
            else {
                cout << res[i];
                cout << endl;
            }
            set.insert(res[i]);
        }
    }
    return 0;
}
