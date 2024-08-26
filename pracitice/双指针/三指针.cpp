#include <iostream>
#include <vector>
using namespace std;
// https://sunnywhy.com/problem/176
const int N = 1e5 + 10;
int a[N],b[N];

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < m; ++j) cin >> b[j];
    vector<int> res(n+m);
    int p = 0,q = 0, k = 0;
    while (p < n && q < m) {
        if (a[p] < b[q]) res[k++] = a[p++];
        else res[k++] = b[q++]; 
    }
    while (p < n) res[k++] = a[p++];
    while (q < m) res[k++] = b[q++];
    for (int i = 0; i < n+m; ++i) {
        if (i < n+m-1) {
            cout << res[i];
            cout << " ";
        }
        else {
            cout << res[i];
            cout << endl;
        }
    }
    return 0;
}