#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], leftMax[N];


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    leftMax[0] = a[0];
    for (int i = 1; i < n; ++i) {
        leftMax[i] = max(leftMax[i-1], a[i] + i);
    }
    int res = 0;
    for (int j = 1; j < n; ++j) {
        res = max(res,leftMax[j-1] + a[j] - j);
    }
    cout << res << endl;
    return 0;
}