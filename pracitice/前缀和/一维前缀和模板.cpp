#include <iostream>
using namespace std;
// 原题链接：https://www.lanqiao.cn/problems/18437/learning/?page=1&first_category_id=1&name=%E5%89%8D%E7%BC%80%E5%92%8C
const int N = 1e5 + 10;
int a[N];
int prefix[N];

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i]; 
    }
    while (q--) {
        int l,r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l-1] << endl;
    }
    return 0;
}