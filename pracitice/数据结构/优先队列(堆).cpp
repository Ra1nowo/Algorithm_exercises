#include <iostream>
#include <queue>
using namespace std;
//https://leetcode.cn/problems/k-th-nearest-obstacle-queries/description/
const int N = 2e5 + 10;
struct {
    int x,y;
}points[N];
int res[N];

priority_queue<int> q;

int main() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> points[i].x >> points[i].y;
    for (int i = 0; i < n; ++i) {
        q.push(abs(points[i].x) + abs(points[i].y));
        if (q.size() < k) res[i] = -1;
        if (q.size() > k) q.pop();
        if (q.size() == k) res[i] = q.top();
    }
    for (int i = 0; i < n; ++i) cout << res[i] << endl;
    return 0;
}