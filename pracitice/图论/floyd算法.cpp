#include <iostream>
#include <cstring>
using namespace std;

const int N = 50;
const int INF = 0x3f3f3f;


int d[N][N];

void floyd(int n) {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (d[i][j] > d[i][k] + d[k][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    fill(d[0], d[0] + N*N, INF);
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v >> w;
        d[u][v] = d[v][u] = w;
    }
    floyd(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (d[i][j] == INF) cout << -1;
            else cout << d[i][j];
            if (j < n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}