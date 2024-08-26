#include <iostream>
#include <algorithm>
using namespace std;
// 原题链接:https://www.lanqiao.cn/problems/110/learning/?page=1&first_category_id=1&second_category_id=3
const int N = 1e6 + 10;
int p[N];
int cnt;

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
    int m,n;
    cin >> m >> n;
    cnt = m * n;
    for (int i = 1; i <= m * n; ++i) {
        p[i] = i;
    }
    int k;
    cin >> k;
    while (k--) {
        int v1,v2;
        cin >> v1 >> v2;
        merge(v1,v2);
    }
    cout << cnt << endl;
    return 0;
}