#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e4 + 10;

struct Interval {
    int l,r;
}interval[N];

bool cmp(Interval a, Interval b) {
    if (a.l == b.l) return a.r > b.r;
    return a.l > b.l;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> interval[i].l >> interval[i].r;
    sort(interval,interval+n,cmp);
    int res = 1, lastl = interval[0].l;
    for (int i = 0; i < n; ++i) {
        if (interval[i].r <= lastl) {
            res++;
            lastl = interval[i].l;
        }
    }
    cout << res << endl;
    return 0;
}