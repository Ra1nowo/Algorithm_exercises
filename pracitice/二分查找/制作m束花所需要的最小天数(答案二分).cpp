#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], m, k, n;

bool check(int days) {
    for (int i = 0; i < n; ++i) {
        b[i] = (a[i] <= days) ? 1 : 0;
    }
    int cntk = 0;
    int groupk = 0;
    for (int j = 0; j < n; ++j) {
        if (b[j] == 1) cntk++;
        else cntk = 0;
        
        if (cntk == k) {
            groupk++;
            cntk = 0;
            if (groupk == m) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    int max_val = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        max_val = max(max_val, a[i]);
    }
    cin >> m >> k;

    int l = 0, r = max_val + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
    return 0;
}
