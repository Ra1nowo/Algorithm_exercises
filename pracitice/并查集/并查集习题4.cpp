#include <iostream>
using namespace std;

const int N = 101;
int p[N],cnt;
// 原题链接:https://sunnywhy.com/problem/363
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
    cnt = n;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    while (m--) {
        int v1,v2;
        cin >> v1 >> v2;
        merge(v1,v2);
    }
    if (cnt == 1) {
        cout << "Yes" << endl;
    }
    else {cout << "No" << endl;}
}