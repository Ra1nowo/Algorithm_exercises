#include <iostream>
#include <algorithm>
using namespace std;
// https://leetcode.cn/problems/reach-end-of-array-with-max-score/
typedef long long ll;
const int N = 1e5 + 10;
ll a[N];


int main() {
    int n;
    cin >> n;
    ll ans = 0, mx = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n-1; ++i) {
        mx = max({mx,a[i]});
        ans += mx;
    }
    cout << ans << endl;
    return 0;
}