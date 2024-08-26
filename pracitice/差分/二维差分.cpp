#include <iostream>
using namespace std;

const int N = 1e3 + 10;
const int M = 1e3 + 10;
int a[N][M];
int b[N][M];


void insert(int x1, int y1, int x2, int y2, int d) {
    b[x1][y1] += d;
    b[x2+1][y1] -= d;
    b[x1][y2+1] -= d;
    b[x2+1][y2+1] += d;
}


int main() {
    int n,m,q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            insert(i,j,i,j,a[i][j]);
        } // 构建差分数组
    }
    while (q--) {
        int x1,x2,y1,y2, d;
        cin >> x1 >> y1 >> x2 >> y2 >> d;
        insert(x1,y1,x2,y2,d);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
            cout << a[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}
