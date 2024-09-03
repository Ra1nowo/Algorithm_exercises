#include <iostream>
#include <climits>
using namespace std;

typedef long long ll;
const int N = 13;
int a[N],n;
ll res = INT_MIN, path = 1;

void dfs(int idx) {
    for (int i = idx; i < n; ++i) {
        if (a[i] != 0) {
            path *= a[i];
            res = max(res,path);
            dfs(i+1);
            path /= a[i];
        }
        else {
            res = max(res,(ll) 0);
            dfs(i+1);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    dfs(0);
    cout << res << endl;
    return 0;
}