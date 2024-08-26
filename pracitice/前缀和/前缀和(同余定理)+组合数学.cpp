#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int prefix[N],a[N];
// 原题链接:https://www.lanqiao.cn/problems/97/learning/?page=1&first_category_id=1&second_category_id=3
int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    unordered_map<int,int> map;
    ll res = 0;
    map[0] = 1;
    for (int i = 1; i <= n; ++i) {
        res += map[prefix[i] % k];
        map[prefix[i] % k]++;
    }
    cout << res << endl;
    // 或者改成：
    // for (int i = 1; i <= n; ++i) map[prefix[i] % k]++;
    // for (int j = 0; j < k; ++j) res += (map[j]-1) * map[j] / 2;
    // cout << map[0]+res << endl;
    return 0;
}