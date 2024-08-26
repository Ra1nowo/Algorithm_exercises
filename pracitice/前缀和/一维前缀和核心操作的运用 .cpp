#include <iostream>
using namespace std;
// 原题链接：https://sunnywhy.com/problem/499
const int N = 1e5 + 10;
int a[N];
int prefix[N];

int main() {
    int n;
    cin >> n;
    int cnt1 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {cnt1++;}
    }
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i-1] + a[i];
    }// 预处理前缀和
    int res = 1e8;
    for (int j = 1; j <= n; ++j) {
        res = min(res,cnt1 - (prefix[j+cnt1-1] - prefix[j-1]));
    }
    cout << res << endl;
}

// 解法2
#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int prefix[N];

int main() {
    int n;
    cin >> n;
    int cnt1 = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {cnt1++;}
    }
    int res = 0;
    for (int i = 1; i <= cnt1; ++i) {
        if (a[i] == 0) {
            res++;
        }
    }
    int ans = res;
    for (int i = cnt1+1; i <=n; ++i) {
        if (a[i] == 0) {
            res++;
        }
        if (a[i-cnt1] == 0) {
            res--;
        }
        ans = min(ans,res);
    } 
    cout << ans << endl;
}