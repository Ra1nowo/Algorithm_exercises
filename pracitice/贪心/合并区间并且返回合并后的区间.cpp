#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;

vector<vector<int>> intervals;
vector<vector<int>> res;

int main() { 
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l >> r;
        intervals.push_back({l,r});
    }
    sort(intervals.begin(),intervals.end());
    res.emplace_back(intervals[0]);
    for (int i = 1; i < n; ++i) {
        if (res.back()[1] < intervals[i][0]) res.emplace_back(intervals[i]);
        else res.back()[1] = max(res.back()[1],intervals[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i][0] << " " << res[i][1] << endl;
    }
    return 0;
}