#include <iostream>
typedef long long ll;
using namespace std;
//原题链接 ：https://www.lanqiao.cn/problems/1276/learning/?page=1&first_category_id=1&second_category_id=8
const int N = 5e5 + 10;
ll a[N],d[N]; // d为差分数组

void insert(int l,int r,int e) {
    d[l] += e;
    d[r+1] -= e;
}

int main() {
    int n,q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        insert(i,i,a[i]);
    }
    while (q--) {
        int l,r,x;
        cin >> l >> r >> x;
        insert(l,r,x);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i-1] + d[i];
    }
    for (int j = 1; j <= n; ++j) {
        ll li = a[j] > 0 ? a[j] : 0;
        cout << li << " ";
    }
    return 0;
}