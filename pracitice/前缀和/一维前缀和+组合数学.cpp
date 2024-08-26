#include <iostream>
using namespace std;
// 原题链接：https://sunnywhy.com/problem/186
const int N = 1e5 + 10;
int a[N];
int cnt0[N];
int cnt2[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        cnt0[i] = cnt0[i-1] + (a[i] == 0 ? 1:0);
    }
    for (int j = 1; j <= n; ++j) {
        cnt2[j] = cnt2[j-1] + (a[j] == 2 ? 1:0);
    }
    long long res = 0;
    for (int k = 1; k <= n; ++k) {
        if (a[k] == 1) {
            res += cnt0[k] * (cnt2[n] - cnt2[k-1]);
        }
    }
    cout << res << endl;
    return 0;
}