#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N],p[N],values[N],cnt;
// 原题链接：https://sunnywhy.com/problem/628/solution/1715571451
int find(int x) {
    if (x != p[x]) {p[x] = find(p[x]);}
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx != ry) {
        p[rx] = ry;
        values[ry] = max(values[ry],values[rx]);
        cnt--;
    }
}

int main() {
    int n;
    cin >> n;
    cnt = n;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
        cin >> a[i];
    }
    for (int j = 1; j <= n; ++j) {
        cin >> values[j];
    }
    for (int i = 1; i <= n; ++i) {
        merge(i,a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << values[find(i)];
        if (i < n) {cout << " ";}
        else {cout << endl;}
    }

    
}