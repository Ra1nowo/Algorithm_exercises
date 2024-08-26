#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N],b[N];

void insert(int l,int r, int d) {
    b[l] += d;
    b[r+1] -= d;
}

int main() {
    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        insert(i,i,a[i]);
    } // 初始化差分数组
    while (m--) {
        int i,j,k;
        cin >> i >> j >> k;
        insert(i,j,k);
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i-1] + b[i];
        cout << a[i] << " ";
    }
    return 0;
} 
