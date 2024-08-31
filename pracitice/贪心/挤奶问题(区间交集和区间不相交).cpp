#include <iostream>
#include <algorithm>
using namespace std;
//https://sunnywhy.com/problem/10004
const int N = 5001;

struct Interval {
    int l, r;
} interval[N];

bool cmp(Interval a, Interval b) {
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> interval[i].l >> interval[i].r;
    sort(interval, interval + n, cmp);

    int L = interval[0].l, R = interval[0].r;
    int freeTime = 0, continueTime = R-L;

    for (int i = 1; i < n; ++i) {
        if (interval[i].l <= R) { // 有交集
            R = max(R, interval[i].r);
        } else {
            continueTime = max(continueTime, R - L);
            freeTime = max(freeTime, interval[i].l - R);
            L = interval[i].l;
            R = interval[i].r;
        }
    }
    cout << continueTime << " " << freeTime << endl;
    return 0;
}
