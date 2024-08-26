#include <iostream>
using namespace std;
// 原题链接：https://sunnywhy.com/problem/596
typedef long long LL;
const int N = 1e5 + 10;
int a[N];
LL preSum[N] = {0};


int main() {
    int n,k,l,r;
    cin >> n >> k >> l >> r;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int j = 0; j < n; ++j) preSum[j] = preSum[j-1] + a[j];
    cout << (r/n)*preSum[n-1]+preSum[r%n]-((l/n)*preSum[n-1]+preSum[(l%n)-1]);
    return 0; 
}