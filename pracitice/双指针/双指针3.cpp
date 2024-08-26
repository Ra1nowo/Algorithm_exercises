// 原题链接：https://www.lanqiao.cn/problems/3640/submissions/66b83380aabe777122483d50/
#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;


const int N = 1e6 + 10;
int a[N];

int main() {
    int n,d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    unordered_map<int,int> cnt;
    for (int i = 0; i < d; ++i) {
        cnt[a[i]]++;
    }
    int res = cnt.size();
    for (int j = d; j < n; ++j) {
        cnt[a[j-d]]--;
        cnt[a[j]]++;
        if (cnt[a[j-d]] == 0) {
            cnt.erase(a[j-d]);
        }
        int update = cnt.size();
        res = min(res,update);   // min(mx, static_cast<int>(c.size()));
    }
    cout << res << endl;
    return 0;
}
