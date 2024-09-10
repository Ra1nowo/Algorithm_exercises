#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int h[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> h[i];
    int l = 0, r = n-1;
    int res = -1;
    while (l < r) {
        int area = (r-l) * min(h[r],h[l]);
        res = max(area,res);
        if (h[l] < h[r]) l++; // 有点贪心的思想了
        else r--; 
    }
    cout << res << endl;
    return 0;
}