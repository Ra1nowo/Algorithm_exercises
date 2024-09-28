#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
vector<vector<int>> points;
string s;
int n;

bool check(int mid) {
    int cnt[26] = {0};
    for (int i = 0; i < n; ++i) {
        if (max(abs(points[i][0]), abs(points[i][1])) <= mid) {
            if (cnt[s[i] - 'a'] < 1) cnt[s[i] - 'a']++;
            else return false;
        } 
    }
    return true;
}


int main() {
    cin >> n;
    points.resize(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = {x,y};
    }
    cin >> s;
    int l = -1, r = 1e9 + 10;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) l = mid;
        else r = mid;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (max(abs(points[i][0]), abs(points[i][1])) <= l) ans++;
    }
    cout << ans << endl;
    return 0;
}