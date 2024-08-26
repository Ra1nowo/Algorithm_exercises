#include <iostream>
#include <algorithm>
#define long long ll;
using namespace std;
// 原题链接: https://www.lanqiao.cn/problems/17098/learning/?page=7&first_category_id=1&sort=difficulty&asc=1&second_category_id=3
const int N = 1e5 + 10;
int n,m;
ll k;
int a[N],b[N];

bool check(ll mid) {
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        ll t = mid - a[i];
        ll curr = upper_bound(b+1,b+m+1,t) - b;
        curr--;
        cnt += curr;
    }
    return cnt >= k;
}


int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    ll l = -1, r = 3e9;
    while (l + 1< r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}