#include <iostream>
using namespace std;

const int N = 2001;

int dp[N][N];

int main() {
    string a, b;
    cin >> a >> b;
    for (int i = 1; i <= a.length(); ++i) {
        for (int j = 1; j <= b.length(); ++j) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[a.length()][b.length()];
    return 0;
}