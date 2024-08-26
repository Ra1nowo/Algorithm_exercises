#include <iostream>
using namespace std;
// 原题链接：https://sunnywhy.com/problem/362
const int N = 1e5 + 10;
int p[N],cnt;

int find(int x) {
    if (x != p[x]) {p[x] = find(p[x]);}
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x),ry = find(y);
    if (rx != ry) {
        p[rx] = ry;
        cnt--;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    while (m--) {
        int v1,v2;
        cin >> v1 >> v2;
        merge(v1,v2);
    }
    int k;
    cin >> k;
    while (k--) {
        int q1,q2;
        cin >> q1 >> q2;
        if (find(q1) == find(q2)) {cout << "Yes" << endl;}
        else {cout << "No" << endl;}
    }
    return 0;
}