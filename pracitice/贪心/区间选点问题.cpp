#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> intervals;

bool cmp(vector<int> &a,vector<int> b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        int l,r;
        cin >> l >> r;
        intervals.push_back({l,r});
    }
    sort(intervals.begin(),intervals.end(),cmp);
    int res = 1;
    int mr = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] > mr) {
            mr = intervals[i][1];
            res++;
        }
        else {
            if (intervals[i][1] < mr) mr = intervals[i][1];
        }
    }
    cout << res << endl;
    return 0;
}