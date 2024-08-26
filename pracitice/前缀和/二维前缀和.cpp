// 原题链接：https://www.lanqiao.cn/problems/18439/learning/?page=1&first_category_id=1&name=%E5%89%8D%E7%BC%80%E5%92%8C
#include <iostream>
using namespace std;

const int N = 1003;
const int M = 1003;
int a[N][M];
int prefix[N][M];

int main() {
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + a[i][j];
        }
    }
    while (q--) {
        int x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][x2-1] << endl;
    }
    return 0;
}