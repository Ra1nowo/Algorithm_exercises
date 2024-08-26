#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
// 原题链接: https://www.lanqiao.cn/problems/172/learning/?page=7&first_category_id=1&sort=difficulty&asc=1&second_category_id=3
const int N = 1e5+10;
int a[N],b[N],c[N];

int main() { 
    int n;    cin >> n;
    for (int i = 0; i < n; i++) {cin >> a[i];}
    for (int i = 0; i < n; i++) {cin >> b[i];}
    for (int i = 0; i < n; i++) {cin >> c[i];};
    sort(a, a + n);     
    sort(c, c + n);
    ll ans = 0;
    for (int i = 0; i < n; i++) { 
        ll x = lower_bound(a, a + n, b[i]) - a;
        ll y = n - (upper_bound(c, c + n, b[i]) - c);
        ans += y*x;
    }
    cout << ans << endl;
}