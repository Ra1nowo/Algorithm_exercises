#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
vector<int> a;

int main() {
    int n, limit;
    cin >> n >> limit;
    for (int i = 0; i < n; ++i) {
        int b;
        a.push_back(b);
    }
    multiset<int> s;
    int res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        s.insert(a[i]);
        while (abs(*s.rbegin() - *s.begin()) > limit) {
            s.erase(a[j++]);
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}