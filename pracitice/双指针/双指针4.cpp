// 原题链接：https://www.lanqiao.cn/problems/3323/learning/?page=1&first_category_id=1&tags=%E5%8F%8C%E6%8C%87%E9%92%88
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <climits>
using namespace std;

const int N = 1e5+10;
char a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int res = INT_MAX;
    unordered_set<char> set;
    for (int i = 0; i < n; ++i) {
        set.insert(a[i]);
    }
    int t = set.size();
    unordered_map<char,int> cnt;
    for (int i = 0, j = 0; j < n; ++j) {
        cnt[a[j]]++;
        while (cnt.size() == t && i < j) {
            res = min(res,j-i+1);
            cnt[a[i]]--;
            if (cnt[a[i]] == 0) {
                cnt.erase(a[i]);
            }
            i++;
        }
    }
    cout << res << endl;
    return 0;
}