#include <iostream>
#include <unordered_set>
using namespace std;
// 原题链接:https://leetcode.cn/problems/unique-length-3-palindromic-subsequences/description/
const int N = 1e5 + 10;
char e[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> e[i];
    }
    int res = 0;
    for (int i = 'a'; i <= 'z'; ++i) {
        int l = 0, r = n-1;
        while (l < n && e[l] != i) l++;
        while (r >= 0 && e[r] != i) r--;
        unordered_set<char> set;
        for (int k = l+1; k < r; ++k) {
            set.insert(e[k]);
        }
        res += set.size();
    }
    cout << res << endl;
    return 0;
}