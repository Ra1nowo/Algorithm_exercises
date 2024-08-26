#include <iostream>
using namespace std;
// https://www.lanqiao.cn/problems/18400/learning/?page=306&first_category_id=1

#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int p[N],cnt;

int find(int x) {
    if (x != p[x]) {p[x] = find(p[x]);}
    return p[x];
}

void merge(int x, int y) {
    int rx = find(x),ry = find(y);
    if (rx != ry) {
        p[ry] = rx;
        cnt--;
    }
}


int main() {
    int n,m,k;
    cin >> n >> m >> k;
    cnt = n;
    for (int i = 1; i <= n; ++i) {
        p[i] = i;
    }
    while (m--) {
        int v1,v2;
        cin >> v1 >> v2;
        merge(v1,v2);
    }
    if (cnt - k <= 0) cout << 0 << endl;
    else cout << cnt - k << endl;
    return 0;
}