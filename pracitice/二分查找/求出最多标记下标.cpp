#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], n;

bool check(int k) {
    for (int i = 0; i < k; ++i) {
        if (2 * a[i] >= a[n-k+i]) return false;
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a,a+n);
    int cnt = 0;
    int l = 0, r = n/2+1;
    while (l + 1 < r) {
        int mid = (l+r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    cout << l * 2 << endl;
    return 0;
}