#include <iostream>
using namespace std;
// https://www.lanqiao.cn/problems/2109/learning/
typedef long long ll;
const int N = 503;
ll a[N][N], s[N][N], sum;


int getSubSum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x2][y1-1] - s[x1-1][y2] + s[x1-1][y1-1];
}

int main() {
    int m, n, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    
    // 计算二维前缀和
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int x = 1; // 初始化 x 变量
            for (int y = 1; y <= m; ++y) {
                // 移动 x 变量直到 sum <= k
                while (x <= y && getSubSum(i, x, j, y) > k) {
                    x++;
                }
                // 计算符合条件的子矩形数目
                if (x <= y) {
                    res += (y - x + 1);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}