#include <iostream>
#include <cstring>
using namespace std;
// https://sunnywhy.com/problem/10039
const int N = 1000;
const int INF = 1e7;
int g[N][N],d[N];
bool vis[N];

int prim(int n){
    int res = 0;
    fill(d,d+n,INF);
    memset(vis,false,sizeof(vis));
    d[0] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1, min_d = INF;
        for (int j = 0; j < n; ++j) {
            if (d[j] < min_d && !vis[j]) {
                min_d = d[j];
                t = j;
            }
        }
        if (t == -1) return -1;
        vis[t] = true;
        res += d[t];
        for (int k = 0; k < n; ++k) d[k] = min(d[k],g[t][k]);
    }
    return res;
}



int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> g[i][j];
        }
    }
    int res = prim(n);
    cout << res << endl;
    return 0;
}