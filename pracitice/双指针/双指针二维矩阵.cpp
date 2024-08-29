#include <iostream>
using namespace std;

const int N = 1001;
const int INF = 1e9;
int a[N][N];

int main() {
    int n,x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int res = INF;
    int i = 0, j = n-1;
    while (i < n && j >= 0) {
        if (a[i][j] > x) {
            res = min(res,a[i][j]);
            j--;
        }
        else i++;
    }
    if (res == INF) cout << -1 << endl;
    else cout << res << endl;
}