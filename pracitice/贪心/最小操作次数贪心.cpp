#include <iostream>
using namespace std;
typedef long long ll;
const int N = 1e5+10;
ll a[N];
//原题链接：https://sunnywhy.com/problem/643/solution/1332849175
int main() {
    int n;
    cin >> n;
    ll res = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n-1; ++i) {
        if (a[i] >= a[i+1]) {
            res += a[i] + 1 -a[i+1];
            a[i+1] = a[i] + 1;
        }
    }
    cout << res << endl;
    return 0;
}