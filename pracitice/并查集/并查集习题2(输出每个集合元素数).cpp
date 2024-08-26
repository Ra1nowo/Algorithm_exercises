#include <iostream>
#include <algorithm>
// 原题链接:https://sunnywhy.com/problem/361/solution/1113995772
using namespace std;
const int N = 101;
int cnt, p[N], csize[N];

int find(int x) {
    if (x != p[x]) {
        p[x] = find(p[x]);
    }
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        p[rx] = ry;
        csize[ry] += csize[rx];
        cnt--;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    cnt = n;
    
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        csize[i] = 1;
    }

    while (m--) {
        int v1, v2;
        cin >> v1 >> v2;
        merge(v1, v2);
    }

    // Print the number of disjoint sets
    cout << cnt << endl;

    // Collect the sizes of all disjoint sets
    int sizes[N] = {0};
    int idx = 0;
    for (int i = 1; i <= n; ++i) {
        if (p[i] == i) { // Only consider root nodes
            csize[idx++] = csize[i];
        }
    }

    // Sort the sizes in descending order
    sort(csize, csize + idx, greater<int>());

    // Print the sorted sizes
    for (int i = 0; i < idx; ++i) {
        cout << csize[i];
        if (i != idx - 1) {
            cout << " ";
        }
    
    }
    return 0;
}