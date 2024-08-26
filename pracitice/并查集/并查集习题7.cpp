#include <iostream>
using namespace std;
// 原题链接：https://www.lanqiao.cn/problems/1135/learning/?page=1&first_category_id=1&second_category_id=8
const int N = 2e5 + 10;
int a[N],p[N],cnt;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x), ry = find(y);
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
        int op,v1,v2;
        cin >> op >> v1 >> v2;
        if (op == 2) {
            string q = find(v1) == find(v2) ? "YES":"NO";
            cout << q << endl;
        }
        if (op == 1) {
            merge(v1,v2);
        }
    }
}