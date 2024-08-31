#include <iostream>
#include <algorithm>
using namespace std;
//https://sunnywhy.com/problem/153/solution/1575245403
const int MAXN = 10000;
struct Interval {    // 区间结构体定义
    int l, r;
} interval[MAXN];    // 区间数组

bool cmp(Interval a, Interval b) {    // 区间的比较函数
    if (a.l != b.l) {                 // 如果左端点不同，那么按左端点从大到小
        return a.l > b.l;
    } else {                          // 否则，按右端点从小到大
        return a.r < b.r;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {         // 输入n个区间的左右端点
        cin >> interval[i].l >> interval[i].r;
    }
    sort(interval, interval + n, cmp);    // 将区间数组进行排序
    int num = 1, lastL = interval[0].l;   // 排序后的第一个区间的左端点总是被选中
    for (int i = 1; i < n; i++) {         // 遍历剩余的区间
        if (interval[i].r < lastL) {      // 如果和上一个选中的区间不相交（注意此处是闭区间，所以不能取到等号）
            lastL = interval[i].l;        // 那么选中当前区间的左端点
            num++;                        // 并令选中的点的数量加1
        }
    }
    cout << num << endl;                    // 输出选中的点数量
    return 0;
}
