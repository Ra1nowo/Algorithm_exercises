#include <iostream>
using namespace std;
//原题链接：https://www.lanqiao.cn/problems/1372/learning/?page=1&first_category_id=1&tags=%E5%8F%8C%E6%8C%87%E9%92%88
const int N = 1e5;
int a[N];

int main() {
    int n,s;
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long total = 0;
    int res = 1e5 + 10;
    for (int i = 0,j = 0; j < n; ++j) {
        total += a[j];
        while (i < j && total >= s) {
            res = min(res,j-i+1);
            total -= a[i];
            i++;
        }
    }
    if (res != 1e5 + 10) {
        cout << res << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}