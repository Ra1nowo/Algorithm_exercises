#include <iostream>
#include <stack>
using namespace std;
// https://leetcode.cn/problems/132-pattern/description/
const int N = 2e5 + 10, INF = -1e9;
int a[N];
stack<int> stk;

bool is132Pattern(int n) {
    int leftMin[n], numsk = INF;
    fill(leftMin,leftMin+n,INF);
    for (int i = 1; i < n; ++i) leftMin[i] = min(leftMin[i-1],a[i-1]);
    for (int j = n-1; j >= 0; --j) {
        while (!stk.empty() && stk.top() < a[j]) {
            numsk = stk.top();
            stk.pop();
        }
        if (numsk > a[j]) return true;
        stk.push(a[j]);
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    string res = is132Pattern(n)? "Yes" : "No";
    cout << res << endl;
    return 0;
}
