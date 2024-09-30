#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], n, k;

int calc1(int k) {
    int cnt = 0, res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i] % 2 == 1) cnt++;
        while (cnt >= k && j <= i) {
            if (a[j] % 2 == 1) cnt--;
            j++;
        } 
        res += j;
    }
    return res;
}

int calc2(int k) {
    int cnt = 0, res = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        if (a[i] % 2 == 1) cnt++;
        while (cnt > k && j <= i) {
            if (a[j] % 2 == 1) cnt--;
            j++;
        } 
        res += i - j + 1;
    }
    return res;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << calc2(k) - calc2(k - 1) << endl; // 等价于 cout << calc1(k) - calc(k+1) << endl;
    return 0;
}