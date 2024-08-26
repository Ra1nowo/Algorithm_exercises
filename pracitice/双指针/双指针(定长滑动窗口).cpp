#include <iostream>
using namespace std;
// https://sunnywhy.com/problem/499
const int N = 1e5 + 10;
int a[N];

int main() {
    int n;
    cin >> n;
    int cnt1 = 0;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) cnt1++;
    }
    int cnt0 = 0;
    for (int i = 0; i < cnt1; ++i) {
        if (a[i] == 0) cnt0++;
    }
    int res = cnt0;
    for (int i = cnt1; i < n; ++i) {
        if (a[i] == 0) cnt0++;
        if (a[i-cnt1] == 0) cnt0--;
        res = min(res,cnt0);
    }
    cout << res << endl;
    return 0; 
}