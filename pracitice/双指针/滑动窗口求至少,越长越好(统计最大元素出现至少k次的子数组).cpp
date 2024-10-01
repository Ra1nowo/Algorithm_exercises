#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5e5 + 10;
int nums[N];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    int mx = -1;
    for (int j = 0; j < n; ++j) {
        mx = max(nums[j], mx);
    }
    int cnt = 0, res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (nums[i] == mx) cnt++;
        while (cnt >= k && j <= i) {
            if (nums[j] == mx) cnt--;
            j++;
        }
        res += j;
    }
    cout << res << endl;
    return 0;
}