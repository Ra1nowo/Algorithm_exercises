#include <iostream>
#include <algorithm>

// https://www.lanqiao.cn/problems/18492/learning/?page=1&first_category_id=1

const int N = 1e5 + 10;
int a[N];

int main() {
    int n, q;
    std::cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    while (q--) {
        int op, l, r, x;
        std::cin >> op >> l >> r >> x;

        if (op == 1) {
            int* it = std::lower_bound(a + l, a + r + 1, x);
            if (it!= a + r + 1 && *it == x) {
                std::cout << it - a << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        } else if (op == 2) {
            int* it = std::upper_bound(a + l, a + r + 1, x);
            if (it!= a + l && *(it - 1) == x) {
                std::cout << it - a - 1 << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        } else if (op == 3) {
            int* it = std::lower_bound(a + l, a + r + 1, x);
            if (it!= a + r + 1 && *it >= x) {
                std::cout << it - a << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        } else if (op == 4) {
            int* it = std::upper_bound(a + l, a + r + 1, x);
            if (it!= a + r + 1 && *it > x) {
                std::cout << it - a << std::endl;
            } else {
                std::cout << -1 << std::endl;
            }
        }
    }

    return 0;
}
