#include <iostream>
using namespace std;
// https://leetcode.cn/problems/consecutive-numbers-sum/description/

int main() {
    int n;
    cin >> n;
    int res = 0;
    for (int k = 1; k*k < 2*n; ++k) {
        if (2*n % k == 0 && ((2*n/k)-k+1) % 2 == 0) res++; 
    }
    cout << res << endl;
    return 0;
}