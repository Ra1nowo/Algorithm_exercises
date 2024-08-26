/*
定义三元组(a,b,c)的距离D = |a-b| + |b-c| + |c-a|
给定3个非空整数集合S1,S2,S3按照升序排列在3个数组中
请设计及一个高效的算法,输出所有可能的三元组中的最小距离D


D = |a-b| + |b-c| + |c-a|
a1 <= a2 <= a3
D = -a1 + a2 + a3 - a2 + a3 - a1 = 2 (a3 - a1) = 2 (max(a,b,c) - min(a,b,c))
*/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    for (int i = 0; i < n1; ++i) cin >> a[i];
    for (int j = 0; j < n2; ++j) cin >> b[j];
    for (int k = 0; k < n3; ++k) cin >> c[k];
    
    int res = 1e9;
    int i = 0, j = 0, k = 0;
    
    while (i < n1 && j < n2 && k < n3) {
        int min_val = min({a[i], b[j], c[k]});
        int max_val = max({a[i], b[j], c[k]});
        res = min(res, 2 * (max_val - min_val));
        
        if (min_val == a[i]) i++;
        else if (min_val == b[j]) j++;
        else k++;
    }
    
    cout << res << endl;
    return 0;
}
