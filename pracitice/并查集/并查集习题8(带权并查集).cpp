// 原题链接：https://www.lanqiao.cn/problems/1156/learning/?page=1&first_category_id=1&second_category_id=8
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int p[N],siz[N],dep[N]; // deepth[N]用来记录当前结点的深度，size[N]用来记录根节点的高度

int find(int x) {
    if (x != p[x]) {
        int t = p[x];
        p[x] = find(p[x]);
        dep[x] += dep[t];
    }
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        dep[rx] = siz[ry];
        siz[ry] += siz[rx];
        p[rx] = ry;
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        siz[i] = 1;
    }
    while (m--) {
        int op, v1, v2;
        cin >> op >> v1 >> v2;
        if (op == 1) merge(v1,v2);
        if (op == 2) {
            int res = find(v1) == find(v2) ? abs(dep[v1] - dep[v2]) - 1 : -1;
            cout << res << endl;
        }
    }
}