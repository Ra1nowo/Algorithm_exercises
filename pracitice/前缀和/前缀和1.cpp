// 原题链接:https://sunnywhy.com/problem/185
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int cnt[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        cnt[i] = cnt[i-1] + (a[i] == 0);
    }
    int res = 0;
    for (int i = n; i >= 0; --i) {
        res += (a[i] == 1)? cnt[i]:0;
    }
    cout << res << endl;
    return 0;
}