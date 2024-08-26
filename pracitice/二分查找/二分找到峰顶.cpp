#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
// https://sunnywhy.com/problem/163
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int l = -1,r = n;
    while (l+1<r) {
        int mid = (l+r)/2;
        if (a[mid] < a[mid+1]) l = mid;
        else r = mid;
    }
    cout << r << endl;
    return 0;
}