#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// https://sunnywhy.com/problem/318

int minOperations(int target) {
    if (target == 1) return 0;

    vector<int> dp(target + 1, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= target; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    return dp[target];
}

int main() {
    int target;
    cin >> target;

    int result = minOperations(target);
    cout << result << endl;

    return 0;
}