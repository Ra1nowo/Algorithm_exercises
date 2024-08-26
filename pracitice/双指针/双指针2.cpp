// 原题链接：https://www.lanqiao.cn/problems/3695/learning/?page=1&first_category_id=1&tags=%E5%8F%8C%E6%8C%87%E9%92%88

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int a[N];

int main() {
    int n,L,R;
    cin >> n >> L >> R;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ll res = 0;
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; ++i) {
        int l = L-a[i],r = R-a[i];
        res += upper_bound(a+i+1,a+n+1,r) - lower_bound(a+i+1,a+1+n,l);
    }
    cout << res << endl;
    return 0;
}